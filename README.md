<h1 align="center">
Desafio Labs - 4 Edição - @42sp
</h1>

<p align="center">
:information_source: Um aplicação de análise e compressão de dados em C
</p>

<p align="center"><a href="https://www.42sp.org.br/" target="_blank"><img src="https://img.shields.io/static/v1?label=&message=SP&color=000&style=for-the-badge&logo=42""></a></p>

<p align="center">
  <a href="#desafio">Desafio</a> :small_blue_diamond:
  <a href="#desenvolvimento">Desenvolvimento</a> :small_blue_diamond:
  <a href="#como-utilizar">Como utilizar</a> :small_blue_diamond:
  <a href="#tecnologias">Tecnologias Utilizadas</a> :small_blue_diamond:
  <a href="#autor">Autor</a>
</p>

<p align="center">🚧 Em construção</p>

<h1 align="center" id="desafio"> 
Desafio
</h1>

Foi proposto durante essa edição do Labs o desenvolvimento de uma aplicação de análise e compressão de dados.
Essa aplicação deve fazer a compressão e descompressão de dados utilizando o algoritmo de Huffman. 
Importante salientar que há um programa diferente responsável por cada etapa 
(Encoder, para  a compressão, e o Decoder, para a descompressão) e eles devem se comunicar por meio de 
_shared memory_.

<h1 align="center" id="desenvolvimento"> 
Desenvolvimento da Aplicação
</h1>

Para simplificar o desenvolvimento, usei algumas plataformas para me planejar e estruturar meu raciocínio.
Uma delas foi o miro, em que criei esse fluxo e o fui moldando ao longo do projeto. Ele resume bem o funcionamento do código:

<p align="center"><a href="https://github.com/42sp/42labs-selection-process-v4-augustobecker">
	<img src="https://user-images.githubusercontent.com/81205527/212546790-1e4e2a48-057f-4c87-8166-4f8adc816b78.png"></a></p>

As possíveis saídas do código não foram colocadas nesse fluxo mas estão muito bem explicitadas em uma função geral de erro,
com uma mensagem de erro setada para cada possível erro na execução, facilitando assim, em muito, debugar o código.
Vale pontuar ainda o uso do Github Projects, um Kanban, para dividir minhas tarefas for etapas. De Todo à já testado:

<p align="center"><a href="https://github.com/42sp/42labs-selection-process-v4-augustobecker">
<img src="https://user-images.githubusercontent.com/81205527/212449251-90f5b5d4-dccc-422f-b38f-c011fccd19e3.png"></a></p>

O desenvolvimento contou ainda com boas pesquisas sobre os mais variados temas:
Algoritmo de Huffman, Shared Memory, Semáforos, Ordenação de Lista, Manipulação de Árvores, Bit arrays e
Producer-Consumer Problem.
Destaco ainda a importância da colaboração com a comunidade da 42, tanto no Discordo quanto algumas aparições presencialmente
para discutir código e possíveis implementações.
	
Dado o prazo do projeto, acredito que fiz um bom progresso, mas caso tivesse mais tempo, tenho algumas ideias do que trabalharia no programa:
* Implementar um bom algorimo de ordenação para a lista de frequência.
* A partir de um certo tamanho de árvore, criar múltiplas threads para fazer a busca dos nós e posteriormente setar os códigos de cada char.
* Uma biblioteca compartilhada para os programas.
* Funções de erro com saídas mais detalhadas.
* Uma forma mais eficiente de transmitir informações por shared memory.
	
<h1 align="center" id="como-utilizar"> 
 Como Utilizar a Aplicação
</h1>

### Execução da Aplicação

1. Clone o repositório

```txt
git clone https://github.com/42sp/42labs-selection-process-v4-augustobecker
```

2. Após isso rode `make` no diretório que acabou de clonar, a aplicação será compilada em ambos os programas (Encoder e Decoder), gerando dois executáveis. Para utilizar a aplicação escreva no terminal ```./encoder/encoder``` junto de um ou mais arquivos de texto para serem comprimidos e ao fim adicione & (para o processo rodar
em segundo plano). Você pode testar com um sample_file que deixei ali para isso.

```shell
./encoder/encoder <file.txt> <...> &
```

3.Logo em seguida,  escreva no terminal ```./decoder/decoder```

```shell
./decoder/decoder
```

Após a execução dos comandos a aplicação será iniciada, e o segundo executável é chamado pelo encoder.
Ao fim, os seguintes dados são printados no terminal:
O Dado descomprimido, a quantidade de bytes totais, a quantidade de bytes comprimidos e o tempo da operação de descompressão.

<h1 align="center" id="tecnologias"> 
Tecnologias Utilizadas
</h1>

| Tecnologia | Descrição |
| --- | --- |
| C | Linguagem utilizada para o dessenvolvimento do projeto.|
| Vscode | Editor de texto.|
| Makefile | Utilizado para automatizar o processo de compilação de aplicações chamando o compilador e informando as "regras" de compilação. |
| Git/GitHub| Utilizado para fazer o versionamento de arquivos e armazenamento.|
| Github Projects | Utilizado para separar o processo de desenvolvimento em etapas e ajudar na organização.
| Miro | Uma plataforma de lousa interativa digital utilizada para desenhar o fluxo do código.|

<h1 align="center" id="autor"> 
Autor
</h1>
<div align="center">
	<div>
	<img height="222em" src="https://user-images.githubusercontent.com/81205527/174709160-f4bc029d-b667-469b-b2a7-4e036f1c5349.png">
	</div>
	<div>
		<strong> Augusto Becker | acesar-l | 🇧🇷👨‍🚀</strong>
	
:wave: Contato:
    	</div> 
    	<div>
  	<a href="https://www.linkedin.com/in/augusto-becker/" target="_blank"><img align="center" alt="LinkedIn" height="60" src="https://user-images.githubusercontent.com/81205527/157161849-01a9df02-bf32-45be-add4-122bc40b48cf.png"></a>
	<a href="https://www.instagram.com/augusto.becker/" target="_blank"><img align="center" alt="Instagram" height="60" src="https://user-images.githubusercontent.com/81205527/157161841-19ec3ab2-2c8f-4ec0-8b9d-3cd885256098.png"></a>
	<a href = "mailto:augustobecker.dev@gmail.com"> <img align="center" alt="Gmail - augustobecker.dev@gmail.com" height="60" src="https://user-images.githubusercontent.com/81205527/157161831-eb9dffee-404b-4ffe-b0af-34671219f7fb.png"></a>
	<a href="https://discord.gg/3kxYkBRxUy" target="_blank"><img align="center" alt="Discord - beckerzz#3614" height="60" src="https://user-images.githubusercontent.com/81205527/157161820-de88dc63-61a3-4c9f-9445-07ac98bf0bc2.png"></a>
	</div>
</div>
