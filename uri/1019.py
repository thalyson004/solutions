# 1019 Conversão de Tempo
segundos = int(input())

horas = segundos//(60*60)
segundos = segundos%(60*60)

minutos = segundos//60
segundos = segundos%60

print(f"{horas}:{minutos}:{segundos}")
