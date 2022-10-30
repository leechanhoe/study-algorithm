import random as rd
import matplotlib.pyplot as plt

MAX_GENE = 1000 # 최대 반복
POP_SIZE = 20 # 염색체 개수
MUT_RATE = 0.3 # 돌연변이 확률
SIZE = 8 # 염색체의 원소 개수
GOAL = 28 # 최적 적합도

'''
구조적으로 한 행에 최대 하나의 퀸만 배치 가능하므로 
1차원 배열로 체스판을 [a, b, c, d, e, f, g, h]로 표현 -> a가 3이면 0행 3열
[3,3, ...]이면 같은 열에 2개가 있어서 중복
'''

class Chromosome:
    def __init__(self, g=[]): # 생성자
        self.genes = g.copy()
        self.fitness = 0
        if self.genes.__len__() == 0:
            for _ in range(SIZE): # 랜덤으로 생성
                self.genes.append(rd.randrange(SIZE))
        self.cal_fitness()
    
    def getFitness(self):
        return self.fitness

    def cal_fitness(self): # 적합도 불러오기
        self.fitness = GOAL # 중복만큼 감소
        
        # 열 중복 체크
        for column in range(SIZE):
            if self.genes.count(column) > 1:
            # count의 개수 = 한 열에 퀸 중복 개수
                self.fitness -= self.genes.count(column)
                
        # \ 대각선 방향 중복 체크
        test = self.genes.copy()
        for i in range(SIZE):
            test[i] += (SIZE - i - 1)
        for rightdown in range(SIZE * 2 - 1):
            if test.count(rightdown) > 1:
                self.fitness -= test.count(rightdown)
        
        # / 대각선 방향 중복 체크
        test = self.genes.copy()
        for i in range(SIZE):
            test[i] += i
        for leftdown in range(SIZE * 2 - 1):
            if test.count(leftdown) > 1:
                self.fitness -= test.count(leftdown)
                
        return self.fitness

def print_p(pop): # 출력
    for i, x in enumerate(pop):
        print(f"염색체 # {i} = {x.genes} 적합도 = {x.getFitness()}")
    print()
    
def select(pop): # 부모 선택
    # 적합도에 비례해 선택하면 안좋은 개체를 선택할 확률이 너무 높으므로 좋은 염색체를 남길 확률 더 증가
    pro = [2 ** i for i in range(SIZE - 1, -1, -1)] 
    pick = rd.uniform(0, sum(pro))
    current = 0
    for c in range(SIZE):
        current += pro[c]
        # 룰렛 알고리즘
        if current > pick:
            return pop[c]
            
def crossover(pop): # 교배
    father = select(pop)
    mother = select(pop)
    half = rd.randrange(1, SIZE) # 염색체 합칠 때 기준점
    child1 = father.genes[:half] + mother.genes[half:]
    child2 = mother.genes[:half] + father.genes[half:]
    return (child1, child2)

def mutate(c): # 돌연변이
    for i in range(SIZE):
        if rd.random() < MUT_RATE: # 랜덤으로 하나 바꾸기
            c.genes[i] = rd.randrange(SIZE)

def getProgress(fitnessMean, fitnessBest, population): # 추이 반영
    fitnessSum = 0 # 평균을 구하기 위한 합계
    for c in population:
        fitnessSum += c.getFitness()
    fitnessMean.append(fitnessSum / POP_SIZE) # 세대의 평균 적합도 추가
    fitnessBest.append(population[0].getFitness()) # 세대의 적합도가 가장 높은 염색체의 적합도 추이

def drawChart(x, fitnessMean, fitnessBest, generation): # 추이 그래프 그리기
    plt.plot(x, fitnessMean, "b", label="mean fitness")
    plt.plot(x, fitnessBest, "r", label="best fitness")
    plt.axhline(GOAL, 0, generation, color='lightgray', linestyle='--')
    plt.axis([0, generation * 1.1, 0, GOAL + 1])
    plt.xlabel("generation")
    plt.ylabel("fitness")
    plt.legend(loc='upper left')
    plt.show()

    
def main():
    population = []
    fitnessMean = [] # 평균 적합도 추이
    fitnessBest = [] # 첫번째 염색체의 적합도 추이

    for _ in range(POP_SIZE):
        population.append(Chromosome())
    population.sort(key = lambda x: x.getFitness(), reverse=True)

    generation = 0
    while 1:
        print("세대 번호 =", generation)
        print_p(population)
        generation += 1
        
        if population[0].getFitness() == GOAL or generation == MAX_GENE:
            getProgress(fitnessMean, fitnessBest, population)
            break
        
        new_pop = []
        
        for _ in range(POP_SIZE // 2):
            c1, c2 = crossover(population)
            new_pop.append(Chromosome(c1))
            new_pop.append(Chromosome(c2))
            
        population = new_pop.copy()
        for c in population:
            mutate(c)
        population.sort(key = lambda x: x.cal_fitness(), reverse=True)

        getProgress(fitnessMean, fitnessBest, population)
        
    drawChart(range(1, generation + 1), fitnessMean, fitnessBest, generation)


if __name__ == '__main__':
    main()