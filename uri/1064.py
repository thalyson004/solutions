# 1064
soma = 0
quantidade = 0

for i in range(6): #[0,1,2,3,4,5]
  valor = float(input())
  if valor>0:
    soma = soma + valor
    quantidade = quantidade + 1

print(f"{quantidade} valores positivos")
print(f"{soma/quantidade :0.1f}")
