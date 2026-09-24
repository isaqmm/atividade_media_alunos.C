listas_alunos = []
menorNota = 0
maiorNota = 0


#CALCULADOR DE MEDIA GERAL DA TURMA

def calcularMediaTotalTurma(media):

    quant = 0
    soma = 0

    for alunos in listas_alunos:

        soma = soma +   alunos[1]
        quant += 1

    media = soma / quant

    return media

#IDENTIFICADOR DE MAIOR E MENOR NOTA DO SISTEMA


def identificarMaiorEMenorNota(lista):

    if not lista:
        print("Nenhum aluno cadastrado!")
        return
    
    maior = lista[0]
    menor = lista[1]

    for aluno in lista:
        if aluno[1] > maior[1]:
            maior = aluno
        if aluno[1] < menor[1]:
            menor = aluno

    print(f"Maior nota: {maior[1]:.2f} - Aluno: {maior[0]}")
    print(f"Menor nota: {menor[1]:.2f} - Aluno: {menor[0]}")   

#FUNÇÃO PRINCIPAL DO SISTEMA COM O OBJETIVO DE ADICIONAR ALUNOS E SUAS NOTAS

def adiocionar_alunoENota(lista):
    soma = 0
    media = 0
    
    aluno = input("Digite o nome do aluno: ")
    for i in range(1, 4):
        nota = float(input(f"Digite a {i}ª nota do aluno: "))
        soma = soma + nota
    print('\n')

    print(f"Aluno {aluno} e sua média foram adicionados a lista com sucesso!")

    print('\n')

    media = soma / 3
    lista.append([aluno, media])

#LISTA DOS ALUNOS APROVADOS

def listarAprovados(lista):

    if not lista:
        print("Nenhum aluno cadastrado!")
        return

    print("=====ALUNOS APROVADOS====")
    for aluno in lista:

        if aluno[1] >= 7:
            print(f"Aluno: {aluno[0]} | Nota: {aluno[1]:.2f}")

#LISTA DOS ALUNOS REPROVADOS


def listarReprovados(lista):

    if not lista:
        print("Nenhum aluno cadastrado!")
        return

    print("=====ALUNOS REPROVADOS====")
    for aluno in lista:

        if aluno[1] < 7:
            print(f"Aluno: {aluno[0]} | Nota: {aluno[1]:.2f}")

#MENU INTERATIVO DO SISTEMA DE GESTÃO DE NOTAS E MÉDIAS


def menu():
    while True:
        print("==================")
        print("MENU PRINCIPAL")
        print("\n")
        print("1 - Cadastrar aluno e suas notas ")
        print("2 - Ver listas de alunos e suas médias")
        print("3 - Calcular a média total da turma")
        print("4 - Identificar Maior e Menor nota")
        print("5 - Listar Alunos Aprovados")
        print("6 - Listar Alunos Reprovados")
        print("7 - SAIR")
        
        print("\n")
        print("==================")

        opcao = int(input("Digite a opção desejada: "))

        match opcao:
            case 1:
                adiocionar_alunoENota(listas_alunos)
            case 2:

                if not listas_alunos:
                    print("\n")
                    print("Nenhum aluno cadastrado!")
                    print("\n")
                
                else:
                    print("\n")
                    print("===========")
                    print("LISTA DE ALUNOS")
                    print("\n")
                    for aluno in listas_alunos:
                        print(f"Aluno: {aluno[0]} | Nota: {aluno[1]:.2f}")

                    print("\n")
                    print("===========")
            
            case 3:
                media = calcularMediaTotalTurma(listas_alunos)
                print(f"A média geral da turma é {media:.2f}")

            case 4:
                identificarMaiorEMenorNota(listas_alunos)
            
            case 5:
                listarAprovados(listas_alunos)
            
            case 6:
                listarReprovados(listas_alunos)

            case 7:
                print("Você saiu do Sistema de Gestão de Notas! Volte Sempre!")
                break
menu()
