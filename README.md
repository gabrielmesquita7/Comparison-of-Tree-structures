<h1 align="center">Comparison of Tree structures</h1>

<p style="font-size:120%;" align="center">
    <a href="#problema">Problema</a> -
    <a href="#desenvolvimento">Desenvolvimento</a> -
    <a href="#resultados">Resultados</a> -
    <a href="#conclusao">Conclusao</a> -
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
- Map -> https://cplusplus.com/reference/map/map/
- Unordered_map -> https://cplusplus.com/reference/unordered_map/unordered_map/

Contêineres de Sequência:
- Vector -> https://cplusplus.com/reference/vector/vector/

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

![img1](https://user-images.githubusercontent.com/55333375/194731924-50d9ce8b-7ad2-4d5a-b061-fe58f3065a3f.jpeg)
![img2](https://user-images.githubusercontent.com/55333375/194731927-ed130d62-b07a-4348-8e6d-5cb8d6581775.jpeg)


## Tempos de execução:
### Foi executado o programa 10 vezes em uma máquina com as seguintes especificações:
- Processador:  AMD RyzenTM 7-3700U Quad Core / Frequência: 2.3GHz até 4.0GHz | 4 MB Cache
- Memória: 8 GB RAM 2400MHz
- Armazenamento: SSD PCIe 3.0 NVMe x4 (M.2 2280)
- Placa Gráfica: AMD Radeon™ RX Vega 10

### Foi encontrado os seguintes resultados:

> Obs: Todos os resultados abaixo são uma média das 10 execuções.

**Tempo de inserção:**
| Entradas         | Arvore BST | Arvore AVL | Arvore RB | Ordenação do Vetor |
|------------------|---------------|---------------|--------------|-----------------------|
| Entrada: 500     |  0.071375895 s  | 0.040012633 s   | 0.038636993 s  | 0.038718883 s           |
| Entrada: 5.000   | 0.049502368 s  | 0.044344231 s   | 0.040032392 s  | 0.046940223 s           |
| Entrada: 50.000  | 0.108930201 s   | 0.102077771 s   | 0.092341233 s  | 0.226538291 s           |
| Entrada: 500.000 | 0.809903102 s   | 0.988999763 s   | 0.760399233 s  | 13.893021357 s          |

> Qual o ganho dessas estruturas ao compará-las a vetores ordenados e aplicados à pesquisa binária. Qual o tempo gasto com a ordenação do vetor? Foi possível produzi-lo em memória? 
**R** = O ganho das estruturas de árvore só é visível após as 50.000 entradas onde é visto um ganho de 124.03% na velocidade e quando são 500.000 entradas esse ganho aumenta consideravelmente visto que o vetor fica 1528.53% mais devagar.

![image](https://user-images.githubusercontent.com/55333375/194733214-286de63d-08b8-4c85-abbd-0e916e5fbb84.png)

**Tempo de pesquisa:**
| Pesquisa | Arvore BST   | Arvore AVL  | Arvore RB   | Map         | Unordered_map |
|----------|--------------|-------------|-------------|-------------|---------------|
| Tempo(s) |  0.017603213 | 0.017392099 | 0.017762319 | 0.162890991 | 0.130098392   |

>Adotando como estrutura o map e unorder_map do C++, há ganhos maiores nesse processo de pesquisa?
**R** = Não foi observado nenhum ganho, pelo contrário, foi observado perda no processo de pesquisa adotando essas estruturas, tendo um aumento de 
mais de 500% no tempo utilizando essas estruturas.

**Tempo de remoção:**
| Remoção  | Arvore BST   | Arvore AVL  | Arvore RB   |
|----------|--------------|-------------|-------------|
| Tempo(s) |  0.017908377 | 0.017600099 | 0.017307893 |

**Comparação entre as Estruturas:**
> média entre as inserções (500, 5000, 50000, 500000)
![Captura de tela de 2022-10-19 11-40-23](https://user-images.githubusercontent.com/55333375/196723099-cc19a663-ac47-4ea9-89c3-3867dc03f4f5.png)

![Captura de tela de 2022-10-19 11-45-56](https://user-images.githubusercontent.com/55333375/196724444-7828bdd8-859b-4590-b6d8-ec71d43ee9be.png)

![image](https://user-images.githubusercontent.com/55333375/194734410-15ca0a57-5399-41ba-abde-777169fc2481.png)


# Conclusao
A inserção dos dados foi feita de modo aleatória e não repetida, ou seja, espera-se que a complexidade das árvores se mantenham no caso médio O(log n). Com isso foi observado que a RedBlack se manteve com menos tempo durante todos os testes obtendo assim a menor média entre as estruturas, outro ponto observado foi que o tempo da AVL aumentou drasticamentente com o aumento do volume dos dados, como por exemplo o aumento da diferença de tempo para a RedBlack no volume de 500.000 dados oque não era tão grande no volume de 50.000 dados, oque era de se esperar já que a AVL tende a ser bastante custosa em grande volumes de dados.

Os dados de entrada que são realmente pesquisados representa somente **2,18%** da quantidade total, ou seja, o tempo de pesquisa e remoção se diferem muito pouco entre as estruturas porque na maioria das vezes será percorrido a árvore inteira e não haverá a remoção, porém mesmo com essa pouca diferença é observado que a **RedBlack** consegue ter o menor tempo na remoção e o maior na pesquisa.

Foi observado que com menor massa de dados o **vetor ordenado** consegue ser a melhor opção, porém o mesmo fica extremamente custoso em grandes massa de dados. O mesmo ocorre para a **map** e **unordered_map** já que para pequenas amostras de dados a estrutura unordered_map consegue ter um custo *O(1)* na pesquisa.

As estruturas de árvore conseguem manter uma média de tempo bem menor que as outras estruturas no geral, porém com o alto numero de dados é observado que a árvore binária e a AVL tendem a ser mais custosas que a RedBlack. Com isso é constatado que as árvores Redblack são de uso mais geral. Eles se saem relativamente bem em adicionar, remover e pesquisar, mas as árvores AVL têm pesquisas mais rápidas ao custo de adicionar/remover mais lentamente. Já que o unico tempo em que a Redblack foi mais custosa é na **pesquisa**.
# Executar
* Como executar:

| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |


# Contatos

<div>
<a href="https://t.me/mesquita776">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 
</a>


<a href="https://www.linkedin.com/in/gabriel-mesquita-pereira-675946229/">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white"/>
</a>
</div>
<p></p>


[![Gmail Badge](https://img.shields.io/badge/-mesquitagabriel30@gmail.com-c14438?style=flat-square&logo=Gmail&logoColor=white&link=mailto:mesquitagabriel30@gmail.com)](mailto:mesquitagabriel30@gmail.com)
