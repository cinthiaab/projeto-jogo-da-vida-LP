# Relatório Final – Jogo da Vida

LP – Laboratório de Programação – PUC-SP -2º sem/2022 - Prof. Julio Araraki

#### **Integrantes do grupo:**

- Cinthia Alves Barreto;
- Igor Matos Gaeta;
- Guilherme Diniz Leocadio;
- Lucas Cassolino D' Azevedo.

### 1. Descrição do jogo do ponto de vista do que realmente aparece nas telas.

1 - Menu principal, primeira tela mostrada ao jogador as opções de criar um novo jogo, recuperar um jogo salvo,  ou sair.

2 - Ao selecionar a opção de Novo Jogo, o jogador terá que escolher o tamanho do mundo, após isso, outro menu aparecerá com as seguintes opções: *Iniciar jogo*, Apresentar Mundo, Limpar o Mundo, Escolher uma célula, Remover uma célula, Salvar Jogo, *Voltar para o Menu Inicial*.

3 – A opção recomendada a se escolher nesse caso é *Escolher uma célula*, tendo em vista que o mundo ainda está vazio. Após esta escolha será necessário que o jogador selecione a posição que ele deseja acrescentar uma nova célula.

3.1 – Após inserir a primeira célula o “mundo” será exibido na tela e a opção de continuar inserindo células ou não.

4  –  Ao  terminar  de  inserir  as  células  o  usuário  retorna  ao  Menu,  sendo recomendado a opção de ***Iniciar jogo.*** Quando selecionada, esta opção apresenta o menu de simulação, possibilitando a escolha de **Gerar a próxima geração (realiza manualmente)**, **Gerar automaticamente (realiza até 10 simulações)** e **interromper a geração**.

5 – Depois de escolher a opção ***Próxima geração***, será exibido apenas uma geração seguinte, e retornando ao menu de simulação.

6 – Selecionando ***Gerar automático (10x)***, será possível escolher quantas gerações seguintes são desejadas e também o intervalo de tempo em que essas simulações são exibidas na tela.

7 – Ao escolher a opção **Interromper Simulação,** voltaremos ao Sub Menu  Principal com as escolhas possíveis citadas no item 2. 

8 – Selecionando Apresentar Mundo, será exibido o mundo caso tenha sido realizada uma simulação anteriormente. 

9  -  Ao  selecionar  Remover  uma  Célula,  poderemos  escolher  uma  célula específica para ser removida do mundo. 

10 – A opção Limpar Mundo remove todas as células e o deixa vazio. 

### 2. Apresentação das telas (suas opções, comentários etc.). 
1 - Menu inicial

![](/Imagens/img01.png)

2 – Sub Menu Principal

![](/Imagens/img02.jpeg)

3- Inserindo uma célula

![](/Imagens/img03.jpeg)

4 – Iniciando o jogo

![](/Imagens/img04.jpegg)

5 – Simulação manual

![](/Imagens/img05.png)

6 – Simulação automática

![](/Imagens/img06.jpeg)

7 – Retornando ao menu de ações do jogo após a simulação

![](/Imagens/img07.png)

8 – Apresentar mundo anterior  

![](/Imagens/img08.png)

9 – Remover uma Célula

![](/Imagens/img09.png)

10 – Limpar o Mundo

![](/Imagens/img10.png)

11 – Salvar jogo

![](/Imagens/img11.png)

12 – Recuperar Jogo (após fechar o arquivo executável e abrir de novo)

![](/Imagens/img12.png)

13 – Padrões de jogo

![](/Imagens/img13.png)

![](/Imagens/img14.jpeg)

14 – Geração automática do padrão 2

![](/Imagens/img15.jpeg)

![](/Imagens/img16.jpeg)![](/Imagens/img17.png)![](/Imagens/img18.png)

## 3. Estruturas de dados usadas (devem estar no “model”)

![](/Imagens/img19.png)

## 4. Organização  do  código  em  termos  de  módulos,  funções  e procedimentos.

**Assinaturas do view**

- void imprimeMatriz() = função que imprime a matriz principal;
- void mensagens(int) = função que armazena todas as mensagens;
- void menuInicialJogo() = função que imprime o menu inicial para o usuário;
- void subMenuPrincipal() = função que contém as opções visuais do menu principal;
- void flush\_in() = função que limpa o console;
- void geracaoView() = função que contém as opções visuais do menu da simulação; 
- void viewPadrao1() = função que exibe ao usuário o padrão 1 de mundo; 
- void viewPadrao2() = função que exibe ao usuário o padrão 2 de mundo; 
- void viewPadrao3() = função que exibe ao usuário o padrão 3 de mundo; 

**Assinaturas Model**

- void geraMatriz() = função que gera a matriz;
- void matrizCopiada() = função que gera matriz auxiliar;
- void matrizPadroes() = função que gera os padrões de mundo ao usuário;  

**Assinaturas Controller**

- void menuInicialJogo() = função com o menu principal do jogo;
- void escolheCelula() = função que permite o usuário escolher quais células ele quer criar;
- void limpaMatriz() = função que limpa a matriz;
- void  removeCelula()  =  função  que  remove  individualmente  as  células  da matriz;
- void iniciarJogo() = função que verifica quais células vão morrer, viver ou nascer;
- int checaLados() = função que checa os lados de cada célula para ver quantas células vivas tem em volta;
- void menuGeracao() = função que armazena o menu para a simulação;
- void menuPadrao() = função que permite criar, selecionar e exibir os padrões de mundo 1,2 e 3;
- void aplicaPadrao1() = função que cria a matriz do mundo de padrão 1;
- void aplicaPadrao2() = função que cria a matriz do mundo de padrão 2;
- void aplicaPadrao3() = função que cria a matriz do mundo de padrão 3;

**Assinaturas Model - Manipulação de arquivos**

- void salvarJogo() = salva todas as variáveis da struct jogo;
- void recuperarJogo() = recupera todas as variáveis da struct jogo.
