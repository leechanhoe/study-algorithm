import pandas as pd

START_MONTH = 7
END_MONTH = 12
df_rent = [None] * 13 # [n] = n월 대여이력
df_broken = [None] * 13 # [n] = n월 고장신고내역


df_rent[7] = pd.read_csv("서울특별시 공공자전거 대여이력 정보_2207.csv")
df_rent[8] = pd.read_csv("서울특별시 공공자전거 대여이력 정보_22081.csv")
df_rent[9] = pd.read_csv("서울특별시 공공자전거 대여이력 정보_2209.csv")
df_rent[10] = pd.read_csv("서울특별시 공공자전거 대여이력 정보_2210.csv")
df_rent[11] = pd.read_csv("서울특별시 공공자전거 대여이력 정보_2211.csv")
df_rent[12] = pd.read_csv("서울특별시 공공자전거 대여이력 정보_2212.csv")
df_broken[0] = pd.read_csv("서울시 공공자전거 고장신고 내역_22.07-12.csv")



def pre_process_rent(df, month):
    df = df[(df['대여일시'] != '0000-00-00 00:00:00') & (df['반납일시'] != '0000-00-00 00:00:00')]
    df['대여일시'] = pd.to_datetime(df['대여일시'])
    df['반납일시'] = pd.to_datetime(df['반납일시'])
    df.drop(['대여거치대', '반납거치대', '대여대여소ID', '반납대여소ID'], axis=1, inplace=True)
    df = df[(df['성별'] == 'M') | (df['성별'] == 'F')]
    df = df[df['생년'] != '1901']
    df = df[df['생년'] != '\\N']
    df["반납대여소번호"] = df["반납대여소번호"].str.replace('\\','')
    df["반납대여소번호"] = df["반납대여소번호"].str.replace('N','-1')
    df['대여요일'] = df['대여일시'].dt.day_name()
    
    return df

for month in range(START_MONTH, END_MONTH + 1):
    df_rent[month] = pre_process_rent(df_rent[month], month)




df_broken[0]['등록일시'] = pd.to_datetime(df_broken[0]['등록일시'])
for month in range(START_MONTH, END_MONTH + 1):
    df_broken[month] = df_broken[0][pd.DatetimeIndex(df_broken[0]['등록일시']).month == month]
    df_broken[month] = df_broken[month].drop_duplicates('자전거번호',keep='last')#마지막 신고이력 남기기


bad = [None] * 13
for month in range(START_MONTH, END_MONTH + 1):    
    broken = pd.merge(df_rent[month], df_broken[month],on='자전거번호')
    broken = broken[broken['대여일시'] <= broken['등록일시']] # 고장신고 이전에 대여된 이력
    broken = broken[broken['대여 대여소명'] != broken['반납대여소명']]# 같은곳에서 반납된것 드랍
    broken = broken[broken['이용시간(분)'] > 2] # 2분이하로 탄 것 드랍

    broken = broken[(broken['등록일시'] - broken['반납일시']) <= pd.to_timedelta(2, unit = 'D')]
    broken = broken.drop_duplicates(['자전거번호'],keep='last')
    broken['고장'] = 1
    
    bad[month] = broken



normal = [None] * 13
for month in range(START_MONTH, END_MONTH + 1):
    good = pd.merge(df_rent[month], df_broken[month],on='자전거번호')
    good = good[good['대여일시'] > good['등록일시']]
    good_first = good.drop_duplicates('자전거번호',keep='first')

    good_exceptfirst = pd.merge(good, good_first, how='outer', indicator=True).query("_merge == 'left_only'").drop(columns=['_merge'])
    good_second = good_exceptfirst.drop_duplicates('자전거번호',keep='first')
    
    good_firstAndSecond = pd.concat([good_first,good_second])
    good_firstAndSecond = good_firstAndSecond[good_firstAndSecond['대여 대여소명'] != good_firstAndSecond['반납대여소명']]#같은곳에서 반납된것 드랍
    good_firstAndSecond = good_firstAndSecond[good_firstAndSecond['이용시간(분)'] > 2]
    
    good_firstAndSecond['고장'] = 0
    
    normal[month] = good_firstAndSecond




train_data = None
for month in range(START_MONTH, END_MONTH + 1):
    bad[month] = bad[month].sample(n=len(normal[month]))
    train = pd.concat([bad[month], normal[month]])
    if month == START_MONTH:
        train_data = train
    else:
        train_data = pd.concat([train_data, train])
    
train_data.sort_values('대여일시')
train_data.head()


train_data.to_csv("training_data7~12.csv", encoding='cp949', index=False)