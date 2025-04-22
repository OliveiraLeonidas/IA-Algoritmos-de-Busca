grafo = {
    'A': ['D','B'],
    'B': ['D','C'],
    'C': ['F'],
    'D': ['G', 'E', 'B'],
    'E': ['G', 'C'],
    'F': [],
    'G': []
}

def objective(estado):
    return 'G' == estado['estado']
    
def expand(estado, g):
    return g[estado['estado']]

pilha = []
estado_inicial = {
                    'estado':'A', 
                    'pai': None
                 }

atual = estado_inicial
while not objective(atual):
    filhos = expand(atual, grafo)
    for filho in filhos:
        folha = {
            'estado': filho,
            'pai': atual
        }
        pilha.append(folha)
    atual = pilha.pop(0)
    
#Recuperar a solução
print("SOLUÇÃO")
while atual != None:
    print(atual["estado"])
    atual = atual['pai']
    
    