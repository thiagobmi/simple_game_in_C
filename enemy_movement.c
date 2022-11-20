void cheatengine(char image[LINHAS][COLUNAS])
{
    randomng();

    if (rngmaster == 1)
    {
        Sleep(10);
        for (int i = 0; i < rng[5]; i++)
        {
            if (image[eixoY][eixoX + 1] != '+' && eixoX < COLUNAS - 1)
            {
                direita2(image);
                if (image[eixoY - 1][eixoX] == '#' || image[eixoY + 1][eixoX] == '#' || image[eixoY][eixoX - 1] == '#' || image[eixoY][eixoX + 1] == '#')
                    teste(image);

                for (int i = 0; i < 7; i++)
                {
                    if (image[eixoY + 1][eixoX] != '+' && eixoY < LINHAS - 1)
                    {
                        baixo2(image);
                        if (image[eixoY - 1][eixoX] == '#' || image[eixoY + 1][eixoX] == '#' || image[eixoY][eixoX - 1] == '#' || image[eixoY][eixoX + 1] == '#')
                            teste(image);
                    }
                }
            }
        }
    }

    for (int i = 0; i < rng[6]; i++)
    {
        Sleep(5);
        if (image[eixoY - 1][eixoX] != '+' && eixoY > 0)
        {
            cima2(image);
            if (image[eixoY - 1][eixoX] == '#' || image[eixoY + 1][eixoX] == '#' || image[eixoY][eixoX - 1] == '#' || image[eixoY][eixoX + 1] == '#')
                teste(image);
            for (int i = 0; i < 7; i++)
            {
                if (image[eixoY][eixoX - 1] != '+' && eixoX > 0)
                {
                    esquerda2(image);
                    if (image[eixoY - 1][eixoX] == '#' || image[eixoY + 1][eixoX] == '#' || image[eixoY][eixoX - 1] == '#' || image[eixoY][eixoX + 1] == '#')
                        teste(image);
                }
            }
        }
    }

    if (rngmaster == 1)
    {
        for (int i = 0; i < 7; i++)
        {
            Sleep(10);
            if (image[eixoY][eixoX - 1] != '+' && eixoX > 0)
            {
                esquerda2(image);
                if (image[eixoY - 1][eixoX] == '#' || image[eixoY + 1][eixoX] == '#' || image[eixoY][eixoX - 1] == '#' || image[eixoY][eixoX + 1] == '#')
                    teste(image);
                {
                    if (image[eixoY - 1][eixoX] != '+' && eixoY > 0)
                    {
                        cima2(image);
                        if (image[eixoY - 1][eixoX] == '#' || image[eixoY + 1][eixoX] == '#' || image[eixoY][eixoX - 1] == '#' || image[eixoY][eixoX + 1] == '#')
                            teste(image);
                    }
                }
            }
        }
    }

    for (int i = 0; i < rng[7]; i++)
    {
        Sleep(5);

        if (image[eixoY + 1][eixoX] != '+' && eixoY < LINHAS - 1)
        {
            baixo2(image);
            if (image[eixoY - 1][eixoX] == '#' || image[eixoY + 1][eixoX] == '#' || image[eixoY][eixoX - 1] == '#' || image[eixoY][eixoX + 1] == '#')
                teste(image);
            for (int i = 0; i < 7; i++)
            {
                if (image[eixoY][eixoX + 1] != '+' && eixoX < COLUNAS - 1)
                {
                    direita2(image);
                    if (image[eixoY - 1][eixoX] == '#' || image[eixoY + 1][eixoX] == '#' || image[eixoY][eixoX - 1] == '#' || image[eixoY][eixoX + 1] == '#')
                        teste(image);
                }
            }
        }
    }

    if (image[eixoY - 1][eixoX] == '#' || image[eixoY + 1][eixoX] == '#' || image[eixoY][eixoX - 1] == '#' || image[eixoY][eixoX + 1] == '#')
        teste(image);

    for (int i = 0; i < rng[1]; i++)
    {
        Sleep(5);

        if (image[eixoY - 1][eixoX] != '+' && eixoY > 0)
            cima2(image);
        if (image[eixoY - 1][eixoX] == '#' || image[eixoY + 1][eixoX] == '#' || image[eixoY][eixoX - 1] == '#' || image[eixoY][eixoX + 1] == '#')
            teste(image);
    }

    for (int i = 0; i < rng[2]; i++)
    {
        Sleep(7);
        if (image[eixoY + 1][eixoX] != '+' && eixoY < LINHAS - 1)
            baixo2(image);
        if (image[eixoY - 1][eixoX] == '#' || image[eixoY + 1][eixoX] == '#' || image[eixoY][eixoX - 1] == '#' || image[eixoY][eixoX + 1] == '#')
            teste(image);
    }

    for (int i = 0; i < rng[3]; i++)
    {
        Sleep(5);
        if (image[eixoY][eixoX + 1] != '+' && eixoX < COLUNAS - 1)
            direita2(image);
        if (image[eixoY - 1][eixoX] == '#' || image[eixoY + 1][eixoX] == '#' || image[eixoY][eixoX - 1] == '#' || image[eixoY][eixoX + 1] == '#')
            teste(image);
    }

    for (int i = 0; i < rng[4]; i++)
    {
        Sleep(5);
        if (image[eixoY][eixoX - 1] != '+' && eixoX > 0)
            esquerda2(image);
        if (image[eixoY - 1][eixoX] == '#' || image[eixoY + 1][eixoX] == '#' || image[eixoY][eixoX - 1] == '#' || image[eixoY][eixoX + 1] == '#')
            teste(image);
    }

    if (image[eixoY - 1][eixoX] != '#' && image[eixoY + 1][eixoX] != '#' && image[eixoY][eixoX - 1] != '#' && image[eixoY][eixoX + 1] != '#')
    {
        for (int i = 0; i < rng[8]; i++)
        {

            if (image[eixoY - 1][eixoX] != '+' && eixoY > 0)
                cima2(image);
            if (image[eixoY - 1][eixoX] == '#' || image[eixoY + 1][eixoX] == '#' || image[eixoY][eixoX - 1] == '#' || image[eixoY][eixoX + 1] == '#')
                teste(image);
        }

        for (int i = 0; i < rng[9]; i++)
        {

            if (image[eixoY + 1][eixoX] != '+' && eixoY < LINHAS - 1)
                baixo2(image);
            if (image[eixoY - 1][eixoX] == '#' || image[eixoY + 1][eixoX] == '#' || image[eixoY][eixoX - 1] == '#' || image[eixoY][eixoX + 1] == '#')
                teste(image);
        }

        for (int i = 0; i < rng[10]; i++)
        {

            if (image[eixoY][eixoX + 1] == '#' && eixoX < COLUNAS - 1)
                direita2(image);
            if (image[eixoY - 1][eixoX] == '#' || image[eixoY + 1][eixoX] == '#' || image[eixoY][eixoX - 1] == '#' || image[eixoY][eixoX + 1] == '#')
                teste(image);
        }

        for (int i = 0; i < rng[11]; i++)
        {

            if (image[eixoY][eixoX - 1] != '+' && eixoX > 0)
                esquerda2(image);
            if (image[eixoY - 1][eixoX] == '#' || image[eixoY + 1][eixoX] == '#' || image[eixoY][eixoX - 1] == '#' || image[eixoY][eixoX + 1] == '#')
                teste(image);
        }
    }
    return 0;
}
void teste(char image[LINHAS][COLUNAS])
{

    if (image[eixoY - 1][eixoX] == '#' && eixoY > 0)
    {
        system("cls");
        cima(image);
        printMatrix(image);
        verificador(image);
    }

    if (image[eixoY + 1][eixoX] == '#' && eixoY < LINHAS - 1)
    {
        system("cls");
        baixo(image);
        printMatrix(image);
        verificador(image);
    }

    if (image[eixoY][eixoX - 1] == '#' && eixoX > 0)
    {
        system("cls");
        esquerda(image);
        printMatrix(image);
        verificador(image);
    }

    if (image[eixoY][eixoX + 1] == '#' && eixoX < COLUNAS - 1)
    {
        system("cls");
        direita(image);
        printMatrix(image);
        verificador(image);
    }
}

void cima2(char image[LINHAS][COLUNAS])
{

    if (image[eixoY - 1][eixoX] != '+' && eixoY > 0)
    {
        system("cls");
        cima(image);
        printMatrix(image);
        verificador(image);
    }
}

void baixo2(char image[LINHAS][COLUNAS])
{

    if (image[eixoY + 1][eixoX] != '+' && eixoY < LINHAS - 1)
    {
        system("cls");
        baixo(image);
        printMatrix(image);
        verificador(image);
    }
}

void direita2(char image[LINHAS][COLUNAS])
{

    if (image[eixoY][eixoX + 1] != '+' && eixoX < COLUNAS - 1)
    {
        system("cls");
        direita(image);
        printMatrix(image);
        verificador(image);
    }
}

void esquerda2(char image[LINHAS][COLUNAS])
{

    if (image[eixoY][eixoX - 1] != '+' && eixoX > 0)
    {
        system("cls");
        esquerda(image);
        printMatrix(image);
        verificador(image);
    }
}

void randomng()
{
    for (int i = 0; i < 15; i++)
    {
        rng[i] = rand() % 14;
        rngmaster = rand() % 1;
    }
}