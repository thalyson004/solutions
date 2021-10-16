# URI Online Judge | 1060

quantidade = 0 # Quantos numeros positivos

for i in range(6): # range(6) [0,1,2,3,4,5]
  if float(input()) > 0.0:
    quantidade = quantidade +1

print(quantidade, 'valores positivos')
