from datetime import datetime, timedelta

# 윤년 확인 함수
def is_leap_year(year):
    return year % 400 == 0 or (year % 4 == 0 and year % 100 != 0)

# 각 달의 일수
months_days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
months = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"]

# 입력
input_date_str = input()

# 입력 파싱
input_date_parts = input_date_str.split()
month = input_date_parts[0]
day = int(input_date_parts[1].rstrip(',')) - 1
year = int(input_date_parts[2])
time = input_date_parts[3]

# 윤년 확인
if is_leap_year(year):
    months_days[1] = 29

# 현재 날짜까지의 일수 계산
days_passed = sum(months_days[:months.index(month)]) + day

# 현재 시간을 일수로 변환하여 더하기
hours, minutes = map(int, time.split(':'))
days_passed += hours / 24 + minutes / (24 * 60)

# 해당 연도의 총 일수 계산
total_days = 365
if is_leap_year(year):
    total_days += 1

# 연도 진행바 계산
progress = (days_passed / total_days) * 100

print(f"{progress:.9f}")