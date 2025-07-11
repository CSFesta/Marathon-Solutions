n = int(input())

for _ in range(n):
    nome = input()
    notas = list(map(float, input().split()))

    if len(notas) == 1:
        media = (notas[0]) / 2
    elif len(notas) == 2:
        media = sum(notas) / 2
    elif len(notas) == 3:
        media = sum(notas) / 3
    elif len(notas) == 4:
        menor = min(notas)        
        notas.remove(menor)        
        media = sum(notas) / 3     

    print(f"{nome}: {media:.1f}")
