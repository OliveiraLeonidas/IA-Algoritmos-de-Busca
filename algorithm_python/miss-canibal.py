# Resolver o problema dos missionários e canibais
# Representação: (me, ce, b, md, cd)

# Verifica se o estado é objetivo
def isObjective(estado):
    return estado == (0, 0, "d", 3, 3)

# Criar as restrições do problema
def isValid(estado):
    (me, ce, b, md, cd) = estado
    if me > 3 or me < 0 or ce > 3 or ce < 0 or \
    md > 3 or md < 0 or cd > 3 or cd < 0:
        return False
    
    if me != 0 and ce > me:
        return False
    
    if md != 0 and cd > md:
        return False
    
    return True

# Executa a expansão de um estado
def expand(estado):
    movimentos = []
    (me, ce, b, md, cd) = estado
    if b == 'e':
        movimentos = [
                (me-2, ce, 'd', md+2, cd),  # 2M para a direita
                (me, ce-2, 'd', md, cd+2),  # 2C para a direita
                (me-1, ce-1, 'd', md+1, cd+1), # 1M1C para a direita
                (me-1, ce, 'd', md+1, cd),  # 1M para a direita
                (me, ce-1, 'd', md, cd+1)   # 1C para a direita
               ]
    else:           
        movimentos = [
                    (me+2, ce, 'e', md-2, cd),  # 2M para a esquerda
                    (me, ce+2, 'e', md, cd-2),  # 2C para a esquerda
                    (me+1, ce+1, 'e', md-1, cd-1), # 1M1C para a esquerda
                    (me+1, ce, 'e', md-1, cd),  # 1M para a esquerda
                    (me, ce+1, 'e', md, cd-1)   # 1C para a esquerda
                   ]
    filhos = []

    for estado in movimentos:
        if isValid(estado):
            filhos.append(estado)
    return filhos

# Busca por largura
no     = {"estado": (3, 3, 'e', 0, 0), "pai": None}
fila   = []
while not isObjective(no["estado"]):
    filhos = expand(no["estado"])
    for filho in filhos:
        folha = {"estado": filho, "pai": no}
        fila.append(folha)
    no = fila.pop(0)

while no != None:
    print(no["estado"])
    no = no["pai"]