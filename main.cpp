
#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>


GLfloat escala;
GLfloat translada;
GLfloat rotaciona;

void display(void)
{
    glMatrixMode(GL_MODELVIEW);

    /*
    Faz com que a matriz corrente seja inicializada com a matriz identidade
    (nenhuma transforma��o � acumulada)
    */
    glLoadIdentity();

    /* Limpa o Buffer de Pixels */
    glClear(GL_COLOR_BUFFER_BIT);

    /* Estabelece a cor*/
    glColor3f (1.0f,1.0f,1.0f);

    /* Efetua a opera��o de transla��o */
    glTranslatef(translada, 0.0f, 0.0f);

    /* Efetua a opera��o de escala em Y */
    glScalef(1.0f, escala, 1.0f);

    /* Efetua a opera��o de rota��o em Z */
    glRotatef(rotaciona, 0.0f, 0.0f, 1.0f);

    /* desenha um simples ret�ngulo */
    glBegin(GL_QUADS);
    glVertex3f (0.025, 0.025, 0.0);
    glVertex3f (0.075, 0.025, 0.0);
    glVertex3f (0.075, 0.075, 0.0);
    glVertex3f (0.025, 0.075, 0.0);
    glEnd();

    /* Inicia o processo de desenho atrav�s dos
    dados bufferizados
    */
    glFlush ();
}
void init (void)
{

    escala = 1;
    translada = 0;
    rotaciona = 0;

/* Seleciona a cor de fundo para limpeza da tela */
   glClearColor (0.0, 0.0, 0.0, 0.0);
}

/*
Fun��o respons�vel pelo controle do teclado. Dependendo da tecla pressionada :
R,S,T, ir� efetuar respectivamente as opera��es de
Rota��o, Escala e Transla��o
*/
void teclado(unsigned char tecla, int x, int y)
{
    switch (tecla) {
        case 'S':
        case 's':// Incrementa o valor do par�metro de escala
            escala = escala + 0.5;
        break;
        case 'T':
        case 't':// Incrementa o valor do par�metro de translacao
            translada = translada + 0.05;
        break;
        case 'R':
        case 'r':// Incrementa o valor do �ngulo de rota��o
            rotaciona = rotaciona - 5.0;
        break;
        case 'O':
        case 'o':
            translada = 0.0;
            escala = 1.0;
            rotaciona = 0;
        break;
    }
    glutPostRedisplay();
}

/*
Func�o principal do programa.
*/
int main(int argc, char** argv)
{

     //Image = new ImageClass();

    /*
    Estabelece o modo de exibi��o a ser utilizado pela janela a ser
    neste caso utiliza-se de um buffer simples, ou seja, a apresenta��o
    execu��o
    Define o modo de cores como RGBA
    */
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);

    /*
    Determina o tamanho em pixels da
    janela a ser criada
    */
    glutInitWindowSize (500, 500);

    /*
    Estabelece a posi��o inicial para cria��o da
    janela
    */
    glutInitWindowPosition (100, 100);

    /*
    Cria uma janela com base nos par�metros especificados
    nas fun��es glutInitWindowSize e glutInitWindowPosition
    com o nome de t�tulo especificado em seu argumento
    */
    glutCreateWindow ("Exemplo - Transforma��es");

    /*
    Habilita a captura dos eventos de teclado
    */
    glutKeyboardFunc(teclado);

    /*
    Especifica os par�metros inicias para as vari�veis
    de estado do OpenGL
    */
    init ();

    // Associa a fun��o display como uma fun��o de callback
    glutDisplayFunc(display);

    /*
    Inicia a execu��o do programa OpenGL.
    O programa ir� executar num loop infinito devendo
    o desenvolvedor especificar as condi��es de sa�da do mesmo
    atrav�s de interrup��es no pr�prio programa ou atrav�s
    de comandos de mouse ou teclado como fun��es de callback
    */
    glutMainLoop();
    return 0;
}
