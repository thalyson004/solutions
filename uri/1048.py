# 1048
salarioAntigo = float(input())
percentual = 0

if salarioAntigo <= 400.0:
  percentual = 15
elif salarioAntigo <= 800.0:
  percentual = 12
elif salarioAntigo <= 1200.0:
  percentual = 10
elif salarioAntigo <= 2000.0:
  percentual = 7
else:
  percentual = 4

reajuste = salarioAntigo*percentual/100
salarioNovo = salarioAntigo + reajuste

print(f"Novo salario: {salarioNovo:.2f}")
print(f"Reajuste ganho: {reajuste:.2f}")
print(f"Em percentual: {percentual} %")
