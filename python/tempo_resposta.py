

tipo_ant = ''
nRep = int(input())
lista = []


for i in range(0, nRep):
    tipo, pessoa = input().split()

    if pessoa not in lista:
        lista.append([pessoa, 0])
    else:

