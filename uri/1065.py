# 1065
quantidade = 0

for i in range(5): #[0,1,2,3,4]
  valor = int(input())
  if valor%2==0:
    quantidade = quantidade + 1

print(f"{quantidade} valores pares")
