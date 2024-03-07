# Read the number of test cases
T = int(input())

# Iterate over each test case
for _ in range(T):
    # Read the equation
    equation = input().split()

    # Split the equation into operand1, operator, and operand2
    operand1 = int(equation[0])
    operator = equation[1]
    operand2 = int(equation[2])

    # Calculate the expected result based on the operator
    if operator == '+':
        expected_result = operand1 + operand2
    elif operator == '-':
        expected_result = operand1 - operand2
    elif operator == '*':
        expected_result = operand1 * operand2
    elif operator == '/':
        expected_result = operand1 / operand2

    # Compare the expected result with the given answer
    given_answer = int(equation[4])
    if expected_result == given_answer:
        print("correct")
    else:
        print("wrong answer")