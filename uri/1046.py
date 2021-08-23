# 1046 Tempo de Jogo
inicio, fim = map(int, input().split())

tempo = fim-inicio
if tempo<=0:
  tempo += 24

print(f"O JOGO DUROU {tempo} HORA(S)")
