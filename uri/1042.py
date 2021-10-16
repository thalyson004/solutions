# URI Online Judge | 1042
valores = list(map(int, input().split()))

valores_c = valores.copy()
valores_c.sort()

for valor in valores_c:
  print(valor)

print("")

for valor in valores:
  print(valor)
