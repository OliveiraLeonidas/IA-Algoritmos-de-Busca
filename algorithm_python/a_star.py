'''
S # # . # . . . .
. # # . # # # # .
. # . . . . . . .
. . . # # # # . #
. # # # . . . . #
. # . . . # # . G
'''
import math
from heapq import heappush, heappop
labirinto = [
            [".","#","#",".","#",".",".",".","."],
            [".","#","#",".","#","#","#","#","."],
            [".",".",".",".","#",".",".",".","."],
            [".","#",".","#","#","#","#",".","#"],
            [".","#",".","#",".",".",".",".","#"],
            [".",".",".",".",".","#","#",".","."],
    ]

def valido(x, y):
    global labirinto
    if x < 0 or x > 8:
        return False
    if y < 0 or y > 5:
        return False
    return labirinto[y][x] == "."

def expand(x, y):
    filhos = [(x, y-1), (x+1, y), (x, y+1), (x-1, y), (x+1, y+1), (x+1, y-1), (x-1, y+1), (x-1, y-1)]
    resultado = []
    for (xf, yf) in filhos:
        if valido(xf, yf):
            resultado.append((xf, yf))
    return resultado

def eObjetivo(estado):
    (_,_, (x, y), _) = estado
    return x == 5 and y == 0

def h(x, y):
    return math.sqrt((5 - x)**2 + (0 - y)**2)

def f(custoAcumulado, x, y):
    return custoAcumulado + h(x, y)

# implementação do A*
atual = (f(0, 0, 0), 0, (0, 0), None)   # (f, custoAcumulado, estado, pai)
fila  = []
while not eObjetivo(atual):
    (x, y) = atual[2]
    filhos = expand(x, y)
    for filho in filhos:
        (xf, yf) = filho
        custoAcumulado = atual[1] + 1
        folha = (f(custoAcumulado, xf, yf), custoAcumulado, filho, atual)
        heappush(fila, folha)
    atual = heappop(fila)

print("Custo total:", atual[1])
while atual != None:
    (xs, ys) = atual[2]
    labirinto[ys][xs] = "@"
    atual = atual[3]

for linha in labirinto:
    strlinha = ""
    for texto in linha:
        strlinha+= " "+texto+" "
    print(strlinha)