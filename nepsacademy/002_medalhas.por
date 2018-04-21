programa
{
	funcao inicio()
	{
		inteiro tempo1, tempo2, tempo3
		leia(tempo1, tempo2, tempo3)

		se( tempo1 < tempo2 e tempo1 < tempo3 ){
			escreva("1\n")
			se( tempo2 < tempo3 ){
				escreva("2\n3\n")
			}senao{
				escreva("3\n2\n")
			}
		} senao se( tempo2 < tempo1 e tempo2 < tempo3 ){
			escreva("2\n")
			se( tempo1 < tempo3 ){
				escreva("1\n3\n")
			}senao{
				escreva("3\n1\n")
			}
		} senao se( tempo3 < tempo1 e tempo3 < tempo2 ){
			escreva("3\n")
			se( tempo1 < tempo2 ){
				escreva("1\n2\n")
			}senao{
				escreva("2\n1\n")
			}
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 217; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */