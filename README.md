<h1>README - Jogo Educativo de Matemática</h1>

<h2>Descrição</h2>
<p>Este é um jogo educativo desenvolvido em C que ajuda os jogadores a praticar operações matemáticas básicas, como soma, subtração, multiplicação e divisão. O jogo possui diferentes níveis de dificuldade e um modo infinito para desafios mais avançados. Ele foi criado com o objetivo de tornar o aprendizado de matemática mais dinâmico e divertido.</p>

<h2>Desenvolvimento</h2>
<p>O jogo foi desenvolvido em <strong>C</strong> utilizando o <strong>Visual Studio Code</strong> como ambiente de desenvolvimento.</p>

<h2>Estrutura do Projeto</h2>
<ul>
    <li><strong>biblioteca.h:</strong> Contém a definição da estrutura <code>Calcular</code>, que armazena informações como dificuldade, valores das operações e pontuação.</li>
    <li><strong>programa.c:</strong> Implementa as funções principais do jogo, incluindo a geração de números aleatórios, verificação de respostas e controle de dificuldade.</li>
    <li><strong>main.c:</strong> Arquivo principal que inicia o jogo chamando a função <code>jogar()</code>.</li>
</ul>

<h2>Funcionalidades Principais</h2>
<ul>
    <li><strong>Seleção de Dificuldade:</strong> O jogador pode escolher entre os níveis <em>Fácil, Médio, Difícil, Insano e Infinito</em>.</li>
    <li><strong>Operações Matemáticas:</strong> O jogo gera aleatoriamente operações de <em>soma, subtração e multiplicação</em>.</li>
    <li><strong>Pontuação:</strong> A pontuação aumenta conforme a dificuldade escolhida.</li>
    <li><strong>Modo Infinito:</strong> O jogo aumenta progressivamente a dificuldade a cada rodada.</li>
    <li><strong>Geração de Números Aleatórios:</strong> Os números das operações são gerados dinamicamente.</li>
</ul>

<h2>Estruturas Utilizadas</h2>
<p>A estrutura Calcular é a principal, responsável por armazenar informações essenciais sobre cada rodada do jogo, incluindo os valores das operações, a dificuldade e a pontuação.</p>

<h2>Uso</h2>
<p>Para compilar e executar o jogo em qualquer máquina, siga os passos abaixo:</p>
<ol>
    <li>Certifique-se de que possui um compilador <strong>C</strong> instalado (como <code>gcc</code>).</li>
    <li>Clone ou baixe os arquivos do projeto.</li>
    <li>No terminal, acesse o diretório do jogo.</li>
    <li>Compile o código com o seguinte comando:</li>
    <pre><code>gcc main.c -o jogo</code></pre>
    <li>Execute o jogo escrevendo "jogo.exe" no terminal.</li>
</ol>

<h2>Dependências</h2>

<p>Compilador C (gcc ou equivalente).</p>
<p>Sistema operacional que suporte comandos cls (Windows) ou clear (Linux/Mac).</p>

<h2>Notas</h2>
<p>A entrada de dados é feita via terminal. Certifique-se de fornecer entradas válidas para evitar erros.</p>

<h2>Licença</h2>
Este projeto é de domínio público e pode ser utilizado e modificado conforme necessário.

