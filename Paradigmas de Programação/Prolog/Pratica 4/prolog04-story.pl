/*
Nesta parte, você deverá criar um programa semelhante a storyfull.pl da prática prolog03, 
para gerar outros textos aleatoriamente, em português ou em inglês. Os textos devem fazer algum sentido, 
mesmo que sejam enredos de ficção.
Você não deve apenas traduzir ou substituir os textos do programa original. 
Também não precisa ser um programa tão longo quanto o original. 
Você deve pensar em diferentes ramificações para o seu texto/enredo e codificá-las em Prolog, 
se inspirando no programa original.
Este é um exercício em que se espera uma produção original de cada estudante. 
Se seu texto/programa for muito semelhante aos demais, haverá desconto na nota.
*/
tellStory([]).
tellStory(P) :- P = choose(L), random_member(M, L), tellStory(M).
tellStory(A) :- atomic(A), write(A), nl.
tellStory([H|T]) :- tellStory(H), tellStory(T).

go :- Story = ['O aluno', Continua],
      Continua = [Comeco, Meio, Fim],
    
      Comeco = ['apos entrar na faculdade', choose(['estava destinado a se formar',
                                                    'nao sabia onde tinha se metido']), Porque],
      
      Porque = ['mais ele tinha um sonho', choose(['agradar sua familia?',
                                                   'aprender excel?',
                                                   'aprenter a formatar o pc?'])],
      
      Meio = ['contudo', choose(['adorou o RU',
                                 'chorou na primeira prova de calculo',
                                 'nao entendia nada de assembly',
                                 ['adorou as aulas da profesora', Professora]])],
      
      Professora = [choose(['Patricia Pitthan',
                            'Andrea Charao',
                            'Giliane Bernardi',
                            'Lisandra Fontoura'])],
      
      Fim = ['por fim', choose(['ele ira desistir?',
                                'aprendera a formatar o pc?',
                                'vai se acostumar com linux?']),'nao perca os proximos capitulos.'],
      tellStory(Story),!.