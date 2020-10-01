# Equipe Wall-E

![Contributions](https://img.shields.io/badge/contributions-welcome-brightgreen.svg)
 ![License](https://img.shields.io/github/license/IFRN-SC/Wall-E-2018-)

- [Resumo](#resumo)
- [Tecnologias utilizadas](#tecnologias-utilizadas)
- [Evolução e Resultados](#evolução-e-resultados)
    - [Premiação OBR 2019](#premiação-obr-2019)
- [Mais Detalhes](#mais-detalhes)
    - [Componentes eletrônicos](#componentes-eletrônicos)
- [Autores](#autores)


## Resumo 

Este respositório contém os códigos utilizados no robô Wall-E da equipe do IFRN Campus Santa Cruz em competições de robótica. A equipe participa de competições como: Amistosos entre campi, Expotec, Secitex e a Olimpíada Brasileira de Robótica (OBR) desde 2017, apresentando ótimos resultados nestas. Em 2019, a equipe foi alvo do projeto premiado na Mostra Nacional de Robótica (MNR), [Byakugan: Visão Computacional](https://github.com/PauloVLB/byakuganv2). Que visava utilizar das tecnologias de reconhecimento e tratamento de imagem para cumprir as tarefas propostas pela OBR, sendo premiada por isso. Você pode acessar o repositório desse projeto clicando [aqui](https://github.com/PauloVLB/byakuganv2). A experiência foi de enorme valia para os estudantes que passaram pela equipe e que participaram da equipe de robótica do campus Santa Cruz. Além de todo conhecimento técnico, tendo contato com as [Tecnologias Utilizadas](##tecnologias-utilizadas), os integrantes passaram por experiências valiosas, como: trabalho em equipe, competições, lidar com suas emoções, entre outras. 

Já passaram pela equipe: Abmael Anderton, [Isaac Marlon](https://github.com/isaacmsl), [Maria Eduarda](https://github.com/MaduSSouza), [Paulo Vitor](https://github.com/PauloVLB), Rosimário Pereira e [Yasmim Araújo](https://github.com/Yasmim066)

## Tecnologias Utilizadas

- [Python](https://www.python.org/) - Linguagem de programação para o middleware ROS;
- [ROS](http://wiki.ros.org/pt_BR/ROS/Tutorials) - Middleware para comunicação Arduino/Raspberry;
- [C++](https://www.cplusplus.com/) - Linguagem de programação para o microcontrolador Arduino;
- [Arduino](https://www.arduino.cc/) - Microcontrolador para os componentes eletrônicos;
- [OpenCV](https://opencv.org/) - Biblioteca de reconhecimento e tratamento de imagens;
- [Raspberry PI](https://www.raspberrypi.org/) - Microprocessador para processamento das imagens;
- [Eagle](https://www.autodesk.com/products/eagle/overview) - Software de prototipagem para Placas de Circuito Impresso;
- [Fritzing](https://fritzing.org/) - Software alternativo de prototipagem para Placas de Circuito Impresso;
- [AutoCad](https://www.autodesk.com.br/products/autocad/overview) - Software de desenho técnico e mecânico para estrutura do robô.

## Evolução e Resultados

Com os ensinamentos dos mestres [Lennedy Campos](https://github.com/lennedy) e [Lucileide Dantas](https://github.com/lucileidedantas), a equipe começou em 2017, com o básico de eletrônica digital e programação, sendo introduzida aos diferentes componentes eletrônicos, e às plataformas citadas em [Tecnologias Utilizadas](##tecnologias-utilizadas).  Passaram-se várias abordagens, testes, estratégias, estudos, noites de discussão, momentos "Eureka!" e interações com todo o grupo do Laboratório de Robótica do IFRN-SC até a última versão de Wall-E:

<div style="display: flex;">
    <img src="https://user-images.githubusercontent.com/31678236/94839273-218db680-03ed-11eb-9c15-3a52a866baa6.png" width="250px" height="300px">
    <img src="https://user-images.githubusercontent.com/31678236/94826043-49751e00-03dd-11eb-931a-83c8e2fb9699.png" width="250px" height="300px">
    <img src="https://user-images.githubusercontent.com/31678236/94839477-6f0a2380-03ed-11eb-8fcc-06eed482c643.png" width="500px" height="400px">
</div>


<p>No ano de 2019, a equipe participou do projeto Byakugan: Visão Computacional, fazendo a equipe ter de refazer toda a estrutura do robô, pois o projeto visava acoplar uma câmera ao robô para usar das tecnologias de visão computacional para cumprir as tarefas propostas pela OBR. Com bastante esforço e dedicação, toda estrutura eletrônica, mecânica e todo o código foi refeito para atingir um bom resultado. Além da câmera, foi introduzido o microprocessador Raspberry PI para o processamentos das imagens capturadas, visto que não era possível o fazer apenas com o Arduino.</p>

<img src="https://user-images.githubusercontent.com/31678236/94826507-c1434880-03dd-11eb-8217-676c4dd79733.png" width="25%">

### Premiação OBR 2019 

Com todo o trabalho feito, a equipe foi premiada na OBR de 2019 com o prêmio de "Inovação", por ser a única equipe utilizando de uma proposta diferente para cumprir os desafios propostos. Tais desafios são usualmente abordados com sensores de distância, luminosidade, som, entre outros. 

<div style="display: flex;">
    <img src="https://user-images.githubusercontent.com/31678236/94827836-4418d300-03df-11eb-90a7-3cedbbe40cfb.png" width="250px" height="300px">
    <img src="https://user-images.githubusercontent.com/31678236/94827912-572ba300-03df-11eb-8f9f-8295af6e8ab5.png" width="250px" height="300px">
    <img src="https://user-images.githubusercontent.com/31678236/94829400-de2d4b00-03e0-11eb-81d5-fe148d7cb243.png" width="500px" height="400px">
</div>



## Mais Detalhes

- [Grupo IFRN-SC](https://github.com/IFRN-SC)
- [Byakugan: Visão Computacional](https://github.com/PauloVLB/byakuganv2)
- [Olimpíada Brasileira de Robótica](http://www.obr.org.br/)
- [IFRN Santa Cruz](https://portal.ifrn.edu.br/campus/santacruz/)

### Componentes eletrônicos

- 1 Arduino Mega
- 1 Raspberry PI 3
- 1 Módulo Câmera Raspberry PI v2
- 1 Regulador de Tensão LM2596
- 1 Acelerômetro e Giroscópio MPU6050
- 3 Sensores HC-SR04
- 1 Bateria de Lítio
- 2 Sensores TCS34725
- 4 Sensores TCRT5000

* Cabos e conectores feitos manualmente

## Autores

| [<img src="https://avatars3.githubusercontent.com/u/31678236?s=400&v=4" width=115><br><sub>@PauloVLB</sub>](https://github.com/PauloVLB) | [<img src="https://avatars3.githubusercontent.com/u/31693006?s=460&v=4" width=115><br><sub>@isaacmsl</sub>](https://github.com/isaacmsl) | [<img src="https://avatars3.githubusercontent.com/u/31935570?s=400&v=4" width=115><br><sub>@Yasmim066</sub>](https://github.com/Yasmim066) |[<img src="https://avatars3.githubusercontent.com/u/49988538?s=400&v=4" width=115><br><sub>@MaduSSouza</sub>](https://github.com/MaduSSouza) | [<img src="https://avatars3.githubusercontent.com/u/4775968?s=400&v=4" width=115><br><sub>@lennedy</sub>](https://github.com/lennedy) | [<img src="https://avatars3.githubusercontent.com/u/30004376?s=400&v=4" width=115><br><sub>@lucileidedantas</sub>](https://github.com/lucileidedantas) |
| :---: | :---: | :---: | :---: | :---: | :---: |
