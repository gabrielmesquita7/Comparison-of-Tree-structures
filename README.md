<h1 align="center">Comparison of Tree structures</h1>

<p style="font-size:120%;" align="center">
    <a href="#problema">Problema</a> -
    <a href="#desenvolvimento">Desenvolvimento</a> -
    <a href="#resultados">Resultados</a> -
    <a href="#executar">Executar</a> -
    <a href="#contatos">Contatos</a>
</p>

# Problema

Até o momento trabalhamos com três modelos de árvore, binária, avl e redblack. Chegou o momento de compararmos tais estruturas, observando seu comportamento sob diferentes volumes de dados. Para tanto, elabore arquivos que contenham 500 , 5000 , 50.000 , 500.000 entradas numéricas do tipo ponto flutuante. Para tanto, tente evitar repetições de valores em grande escala para que possamos ter uma estrutura profunda. Considere produzir os menores a partir dos maiores volumes de forma randômica. Feito a isso, vamos testar os seguintes processos:

1) - Qual o tempo gasto com pesquisa para um arquivo de entrada com 10.000 consultas. Considere como consulta a busca de um determinado número na estrutura escolhida. Para cada pesquisa, é preciso remover o elemento da árvore, retornando esse número para o usuário. Então, considere o processo de remoção como parte final do processo. 

2) - Qual o tempo necessário para montar a estrutura em memória. 

3) - Qual o ganho dessas estruturas ao compará-las a vetores ordenados e aplicados à pesquisa binária. Qual o tempo gasto com a ordenação do vetor? Foi possível produzi-lo em memória? 

4) - Adotando como estrutura o map e unorder_map do C++, há ganhos maiores nesse processo de pesquisa?

Elabore um relatório detalhando a implementação dessas estruturas, funcionamento da aplicação, exemplo de resultado, modo de compilação e conclusões. Considere essa última seção como uma discussão de quando adotar cada estrutura acima citada e o por quê de tal escolha. Para toda essa discussão, apresentar gráficos que demonstrem os resultados obtidos durante o processo de análise. 
 

# Desenvolvimento
## O problema foi desenvolvido da seguinte maneira:
### Implementação das estruturas:
Foi implementado as seguintes estruturas no trabalho:

Árvores:
- Árvore binária de busca
- Árvore AVL
- Árvore rubro-negra

> Para a implementação das árvores foi utilizado as estruturas prontas fornecidas pelo professor e alterado alguns trechos de código para melhor se adequar ao cenário proposto. Como por exemplo: 

*Tree.cpp*
```cpp
void removeTree(Tree **t, Record r)
{
    ...
    deleted_elements.push_back((*t)->reg.key);
    ...
}
```
> Para cada vez que é chamado a função de remoção e é verificado que o elemento está dentro da árvore, a key {float} é armazenada dentro do vector para retornar ao usuário ao fim do programa.

Contêineres Associativos:
- Map
- Unordered_map

Contêineres de Sequência:
- Vector

> Todas essas estruturas já estão implementadas como bibliotecas no C++, basta chamá-las.
 ```cpp
#include <vector>
#include <map>
#include <unordered_map>
```
### Inserção dos dados:

Foi criado os arquivos **tools.hpp** e **tools.cpp** para armazenar as funções que irão pegar os dados armazenados nos arquivos **.txt** e irão armazena-los nas estruturas de dados; primeiro inserindo e depois manipulando os dados (pesquisa e remoção).

>Obs: todas as funções tem como parâmetro o nome do arquivo para diferenciar o arquivo com os numeros a serem inseridos(*data.txt*) com os numeros de entrada para a pesquisa(*search.txt*).

```cpp
Tree *InsertDataBinaryT(string filename, int qtd);
AvlTree *InsertDataAvlT(string filename, int qtd);
RBTree InsertDataRbT(string filename, int qtd);
vector<float> InsertDataVector(string filename, int qtd);
map<float, int> InsertDataMap(string filename);
unordered_map<float, int> InsertDataUnordMap(string filename);

void searchDataBinaryT(string filename, Tree *raiz);
void searchDataAvlT(string filename, AvlTree *Avlraiz);
void searchDataRB(string filename, RBTree rb);
void searchDataMap(string filename, map<float, int> datamap);
void searchDataUnordMap(string filename, unordered_map<float, int> unordmap);

void RemoveDataBinaryT(string filename, Tree *raiz);
void RemoveDataAvlT(string filename, AvlTree *Avlraiz);
```

### Medição do tempo:
Para medir o tempo gasto com pesquisa, inserção e remoção dos elementos nas estruturas foi criado os arquivos **time.hpp** e **time.cpp** que contém as funções que irão medir o tempo de cada ação separadamente.

```cpp
void resetTimes();
void measure_timeInsert(int qtd);
void measure_timeSearch();
void measure_timeRemove();
void measure_time();
```
Afim de obter um resultado de tempo mais preciso foi utilizado a biblioteca **Chrono**. Sendo uma biblioteca projetada para lidar com o fato de que temporizadores e relógios podem ser diferentes em sistemas diferentes e, portanto, melhorar ao longo do tempo em termos de precisão.

**Clock:** Consiste em um ponto de partida e uma taxa de ticks.

O tipo de clock escolhido foi o **high_resolution_clock** por fornece o menor período de ticks possível.

Exemplo: *time.cpp*
```cpp
void measure_timeInsert(int qtd){
    auto start1 = chrono::high_resolution_clock::now();
    Tree *raiz = CreateTree();
    raiz = InsertDataBinaryT("data.txt", qtd);
    auto end1 = chrono::high_resolution_clock::now();
    binaryTime = chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();
}
```
Por fim foi criado a função **core** do projeto, onde é medido o tempo de cada estrutura para cada ação (inserção, remoção e pesquisa) e retornado ao usuário os tempos organizados na forma sugerida pelo **problema**.
```cpp
void measure_time()
{
    void measure_timeInsert(int qtd); //500;5.000;50.000;500.000
    void measure_timeSearch();
    void measure_timeRemove();
}
```
# Resultados
### A saida esperada para o programa:
saida.jpg

## Tempos de execução:
### Foi executado o programa 10 vezes em uma máquina com as seguintes especificações:
- Processador:  AMD RyzenTM 7-3700U Quad Core / Frequência: 2.3GHz até 4.0GHz | 4 MB Cache
- Memória: 8 GB RAM 2400MHz
- Armazenamento: SSD PCIe 3.0 NVMe x4 (M.2 2280)
- Placa Gráfica: AMD Radeon™ RX Vega 10

### Foi encontrado os seguintes resultados:
tabelas e 
graficos


# Executar
* Como executar:

| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |


# Contatos

<div style="display: inline-block;">
<a href="https://t.me/mesquita776">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 
</a>

<a href="https://www.linkedin.com/in/gabriel-mesquita-pereira-675946229/">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white"/>
</a>

</div>

<a style="color:black" href="mailto:michel@cefetmg.br?subject=[GitHub]%20Source%20Dynamic%20Lists">
✉️ <i>mesquitagabriel30@gmail.com</i>
</a>

<p> </p>