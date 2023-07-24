if __name__ == '__main__':
    n = int(input())
    student_marks = {}
    for _ in range(n):
        name, *line = input().split()
        scores = list(map(float, line))
        student_marks[name] = scores
    query_name = input()
    val_query_name = student_marks.get(query_name)
    suma = 0
    for i in val_query_name:
        suma +=i
    prom_query_name = suma/len(val_query_name)
    print("{:.2f}".format(prom_query_name))