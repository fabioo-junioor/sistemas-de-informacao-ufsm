1. Quais as classes definidas nos arquivos DesktopLauncher.java e Drop.java?  
DesktopLauncher.java -> classe DesktopLauncher  
Drop.java -> classe Drop

2. Explique como o conceito de herança em Java se aplica às classes definidas nestes arquivos.  
Sem a necessidade de criaçao de classes especificas. Muita coisa é herdada da classe 'ApplicationAdapter' da biblioteca gdx.

3. Em qual classe estão os atributos que representam as gotas que "caem" no balde?  
Na classe 'drop' no metodo 'spawRaindrop'.

4. Quais são os atributos que representam a imagem e a posição das gotas?  
raindrop.x = MathUtils.random(0, 800-64);  
raindrop.y = 480;  
raindrop.width = 64;  
raindrop.height = 64;  
raindrops.add(raindrop);

5. Em Drop.java, no método spawnRaindrop(), o que você consegue deduzir sobre a visibilidade (public, private, protected) do atributo raindrop.x?  
É um atributo privado a classe drop.

6. Ainda no método spawnRaindrop(), MathUtils é um nome de classe ou uma referência para um objeto?  
Acho que é nome de uma classe.

7. Também em spawnRaindrop(), por que lastDropTime pode ser usado sem estar declarado dentro deste método?  
Porque ele esta declarado dentro da classe 'drop'.

8. O mecanismo de herança permite que uma classe filha aproveite "algo" definido em uma classe mãe. Também se pode dizer que a classe mãe transmite "algo" para a classe filha. O que está sendo transmitido neste exemplo de jogo?  
Tudo praticamente, a maioria é herdado da classe 'ApplicationAdapter'.