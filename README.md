# Projeto-AFP
Repositório dedicado ao projeto de AFP

1 Introdução
    O objetivo deste projeto é desenvolver uma aplicação em consola, utilizando a linguagem C ANSI e a
    abordagem procedimental e modular, por forma a implementar um sistema de gestão de reservas de lotes
    de um parque de campismo.
    No problema a modelar destacam-se as seguintes entidades:
        • Campista;
        • Lote e Registo de Reserva;
        • Mapa do Parque;
        • Menu.
        2 Detalhes de Implementação
2.1 Campista.
    Um campista representa uma pessoa que faz parte de uma reserva de um determinado lote do parque.
    Deve registar-se o nome e a idade de cada campista.
2.2 Lote e Registo de Reserva
    Para cada lote deve ser registada informação sobre:
        1. A reserva atual do lote;
        2. O histórico das últimas 3 reservas efetuadas nesse lote (ordenadas da mais recente para a mais
        antiga).
    Por sua vez, uma reserva deve registar:
        1. O tipo de alojamento (tenda, caravana ou autocaravana);
        2. Se tem ligação à rede elétrica;
        3. Os dados do(s) campista(s);
        4. A tarifa a pagar (pode assumir que a tarifa representa um pagamento único por reserva, ou assumir que a tarifa é aplicada tendo em conta o número de dias reservados).
    Cada reserva pode alocar no máximo 6 campistas, que devem estar ordenados nos registos por ordem
    decrescente de idade.
    O total da tarifa a pagar por cada reserva depende da sua composição e é calculada segundo a seguinte
    tabela:
        TENDA 4,50 €
        CARAVANA 6,00 €
        AUTOCARAVANA 14,90 €
        ELECTRICIDADE 3,00 €
        CAMPISTA 3,50 €
    e.g. uma reserva para uma tenda, eletricidade e 2 campistas pagará uma tarifa de: 4,50 + 3,00 + (2x3,50) = 14,50 €.
2.3 Mapa do Parque
    O mapa do parque deverá mostrar todos os lotes existentes assinalando os lotes livres/reservados, bem
    como a contagem total de lotes livres e a percentagem de ocupação atual do parque.
    Considere que o parque disponibiliza inicialmente 25 lotes representando-os, por exemplo, com uma matriz
    5x5. No entanto, considere ainda que estes valores devem poder ser facilmente alterados por forma a
    permitir a possibilidade de representar um parque com outras dimensões.
    Sugere-se, de seguida, uma apresentação simplista do mapa contendo a informação mais relevante das
    características de cada reserva atual de cada lote:
    Sugestão de apresentação do Mapa de Lotes.
    No mapa apresentado, os lotes são identificados por coordenadas LinhaColuna (correspondentes às
    posições da matriz) e mostra a seguinte informação: tipo de alojamento; existência de ligação à rede
    elétrica; número de campistas na reserva atual (e.g. o lote 2 1 (Te4) está reservado para uma Tenda com
    eletricidade e 4 campistas).
2.4 Menu
    O Menu deverá disponibilizar opções para:
        1. Visualizar o mapa atualizado do parque;
        2. Reservar um lote e registar os seus detalhes;
        3. Consultar os detalhes de um determinado lote (detalhes da reserva atual e do histórico);
        4. Pesquisar lote por nome de campista (i.e. localizar em que reserva de lote está atualmente alojado
        determinado campista);
        5. Editar a informação da reserva atual de um lote (tipo de alojamento, ligar eletricidade,
        adicionar/remover campistas);
        6. Libertar a reserva atual de um lote para que fique disponível para nova reserva (adicionando
        essa reserva atual ao histórico);
        7. Sair da aplicação;
        8. Outras funcionalidades que considere que se justifiquem.
        NOTA: Deverão ser efetuadas todas as validações necessárias (e.g. verificar se opções introduzidas são
        válidas e se têm o formato esperado; verificar se o lote a reservar existe e se está livre; etc.
