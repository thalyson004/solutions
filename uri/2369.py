consumo = int(input())
conta = 0

if consumo <= 10:
  conta = 7
elif consumo <= 30:
  conta = 7 + (consumo-10)*1
elif consumo <= 100:
  conta = 7 + 20 + (consumo-30)*2
else:
  conta = 7 + 20 + 140 + (consumo-100)*5

print(conta)
