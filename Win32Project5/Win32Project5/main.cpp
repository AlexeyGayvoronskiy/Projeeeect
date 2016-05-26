#include "Project.h"
#include "iostream"
using namespace std;

// ������ ����. ������ ��������� � ������� ������ ���� 128x128 ��������
const int GRID_SIZE_X = 1024;
const int GRID_SIZE_Y = 768;

class TicTacToeScreen : public Screen
{
private:
	Input* input;
	Graphics* graphics;

	// ����������� ����, ��������� � �������
	Image* back;
	Image* packman;
	Image* kirpich;
	Image* gameback;
	Image* levelback;
	Image* life;
	Image* pobeda;
	Image* number[3];
	Image* kirp;
	Image* prozr;
	Image* titry;
	Image* levelchng;
	Image* enh;
	Mix_Music *music = NULL;
	int cond = 0;
	int k = 0, h;
	char q = 'p';
	int lvl, dif = 10;

	void StartSettings()
	{
		// ����� ������� Graphics � Input � ������������� ��������� ����

		input = game->GetInput();
		graphics = game->GetGraphics();
		SDL_WM_SetCaption("SHAMAN KING", 0);
	}

	void LoadingImage()
	{
		// �������� �����������

		back = graphics->NewImage("C:\\Users\\user\\Desktop\\images\\menu.bmp");
		packman = graphics->NewImage("C:\\Users\\user\\Desktop\\images\\Packman.bmp");
		SDL_SetColorKey(packman->surf, SDL_SRCCOLORKEY, SDL_MapRGB(packman->surf->format, 255, 255, 255));
		kirpich = graphics->NewImage("C:\\Users\\user\\Desktop\\images\\kirpich.bmp");
		SDL_SetColorKey(kirpich->surf, SDL_SRCCOLORKEY, SDL_MapRGB(kirpich->surf->format, 255, 255, 255));
		gameback = graphics->NewImage("C:\\Users\\user\\Desktop\\images\\pole.bmp");
		levelback = graphics->NewImage("C:\\Users\\user\\Desktop\\images\\LevelSelection.bmp");
		life = graphics->NewImage("C:\\Users\\user\\Desktop\\images\\life.bmp");
		SDL_SetColorKey(life->surf, SDL_SRCCOLORKEY, SDL_MapRGB(life->surf->format, 255, 255, 255));
		pobeda = graphics->NewImage("C:\\Users\\user\\Desktop\\images\\pobeda.bmp");
		kirp = graphics->NewImage("C:\\Users\\user\\Desktop\\images\\kirpichik.bmp");
		prozr = graphics->NewImage("C:\\Users\\user\\Desktop\\images\\prozrachniy.bmp");
		titry = graphics->NewImage("C:\\Users\\user\\Desktop\\images\\titry.bmp");
		enh = graphics->NewImage("C:\\Users\\user\\Desktop\\images\\ENH.bmp");
		levelchng = graphics->NewImage("C:\\Users\\user\\Desktop\\images\\LevelChange.bmp");
		music = Mix_LoadMUS("C:\\Users\\user\\Desktop\\Hermanos_Inglesos_Feat.wav");
		lvl = 1;
	}

	void Reset()
	{
		// ������� ���� � ����� ����

		cond = 0;
		graphics->DrawImage(back, 0, 0);
		graphics->Flip();
	}

	int GameOver()
	{
		return 1;
	}

	void GameOverHandle(int over)
	{
		// ��������� ����� ����


		// ���������� ������������, ����� �� �� ������� ��� ���

	}

public:
	void Start()
	{
		StartSettings();
		LoadingImage();
		Reset();
	}

	void Update()
	{
		if (input->IsExit())
			game->Exit();
		if (cond == 0)
		{
			if (Mix_PlayingMusic() == 0)
			{
				//��������� ������������� ������
				Mix_PlayMusic(music, -1);
			}
			lvl = 1;
			graphics->DrawImage(back, 0, 0);
			graphics->Flip();
			if (input->IsMouseButtonDown(1))
			{
				// ����� ���������� ������� ������
				int x = input->GetButtonDownCoords().x / (GRID_SIZE_X / 4),
					y = input->GetButtonDownCoords().y / (GRID_SIZE_Y / 9);

				// ���� �� ������ �� ������ ������
				if (((x == 1) | (x == 2)) & (y == 1)) /*��������� ����*/
				{
					cond = 1;
				}
				if (((x == 1) | (x == 2)) & (y == 3))
				{
					cond = 6;
				}
				if (((x == 1) | (x == 2)) & (y == 5))
				{
					//Sleep(200);
					cond = 4;
					while (!input->IsMouseButtonUp(1))
						input->Update();
					/*��������� ���������*/
				}
				if (((x == 2) | (x == 1)) & (y == 7))
				{
					game->Exit();
					while (!input->IsMouseButtonUp(1))
						input->Update();
				}
			}
			if (input->IsKeyDown('e'))
			{
				cond = 7;
			}
		}
		if (cond == 1)
		{
			//�������� �������� � ����� (cond = 4) ��������� �������� ����� ������ ����� ���� 
			//������� ������
			//������� ���������
			int x[10], y = 476, j;
			int lifes = 3;
			FILE *in;

			while (cond == 1){
				if (lvl == 1) {
					in = fopen("C:\\Users\\user\\Desktop\\images\\lvls\\1.txt", "r");
					for (int i = 0; i < 10; i++)
						fscanf(in, "%i", (&x[0] + i));
				}
				if (lvl == 2) {
					in = fopen("C:\\Users\\user\\Desktop\\images\\lvls\\2.txt", "r");
					for (int i = 0; i < 10; i++)
						fscanf(in, "%i", (&x[0] + i));
				}
				if (lvl == 3) {
					in = fopen("C:\\Users\\user\\Desktop\\images\\lvls\\3.txt", "r");
					for (int i = 0; i < 10; i++)
						fscanf(in, "%i", (&x[0] + i));
				}
				if (lvl == 4) {
					in = fopen("C:\\Users\\user\\Desktop\\images\\lvls\\4.txt", "r");
					for (int i = 0; i < 10; i++)
						fscanf(in, "%i", (&x[0] + i));
				}
				if (lvl == 5) {
					in = fopen("C:\\Users\\user\\Desktop\\images\\lvls\\5.txt", "r");
					for (int i = 0; i < 10; i++)
						fscanf(in, "%i", (&x[0] + i));
				}
				if (lvl == 11) {
					in = fopen("C:\\Users\\user\\Desktop\\images\\lvls\\11.txt", "r");
					for (int i = 0; i < 10; i++)
						fscanf(in, "%i", (&x[0] + i));
				}
				if (lvl == 12) {
					in = fopen("C:\\Users\\user\\Desktop\\images\\lvls\\12.txt", "r");
					for (int i = 0; i < 10; i++)
						fscanf(in, "%i", (&x[0] + i));
				}
				if (lvl == 13) {
					in = fopen("C:\\Users\\user\\Desktop\\images\\lvls\\13.txt", "r");
					for (int i = 0; i < 10; i++)
						fscanf(in, "%i", (&x[0] + i));
				}
				int max = x[0];

				for (int i = 0; i < 10; i++)
				{
					if (x[i] > max)
					{
						max = x[i];
					}
				}
				int a = 1, jump = 0, uppoint = 0, padaet = 1;//������ ����, ��� �� � �������� ����, ������, ���������� ������� �����
				int xp = 187, yp = 476, b = 0, c = 30;; //���������� �������, ��������� ����� ����� ��� ���� � ���������
				int stpr = 20; //����������, ������� ��������, ��� ��� ������ ����� �������� ����


				//���� a == 1 �� �� ���������� � ����
				while (a)
				{
					if (lifes == 0){
						cond = 0;
						a = 0;
					}
					input->Update();
					for (int i = 0; i < 10; i++) {
						if (((xp + 174) >= x[i]) && ((yp + 87) >= y) && (xp + 87 <= x[i]))
						{
							lifes = lifes - 1;
							a = 0;
							cond = 1;
						}
					}
					if (input->IsExit())
					{
						game->Exit();
						a = 0;
						cond = 0;
					}
					j = 0;
					//��������� �����
					if (input->IsKeyDown('f'))
					{
						j = -10;
					}
					//��������� ������
					if (input->IsKeyDown('g'))
					{
						j = 10;
					}
					//������� �� ����
					if (input->IsKeyDown(SDLK_ESCAPE))
					{
						a = 0;
						cond = 0;
					}
					//���������� ������ 
					//���� ���������� ������������ ������ ���, ���� ���� ������ �������� �� �������, ������� ���� ������ ������� ������� 
					if (input->IsKeyDown(SDLK_SPACE) && (stpr <= 50))
					{
						stpr = stpr + 1;
					}
					if ((input->IsKeyUp(SDLK_SPACE)) && (stpr > 20))
					{
						jump = 1;
					}



					//�����, ������� �� ��������� � ������
					while (jump == 1)
					{
						j = 0;
						//�������� � ������� �� ����� ������
						if (input->IsKeyDown('f'))
						{
							j = -10;
						}
						if (input->IsKeyDown('g'))
						{
							j = 10;
						}
						input->Update();
						//���� �� ����� �� �����������
						/*	if ((xp >= x[i] - 87) && (yp = y - 174) && (xp <= x[i]))
						{
						jump = 0;
						stpr = 0;
						}
						yp = yp + stpr;
						stpr--;
						if (yp >= y + 174)
						{
						jump = 0;
						}
						*/
						for (int i = 0; i < 10; i++){
							if (xp >= x[i])
							{
								padaet = 1;
							}
						}
						//������� �� ���������� �� �����������
						//����������, ��� b �������� �������� ��������� ������ ����� ��� ����
						//���� ����� ���������� �� ���������� padaet

						if (padaet == 1)
						{
							//��� ���� �������, ��������� ����������� �������� ����������� ������ �� ������ ������ 
							yp = yp - stpr;
							stpr--;
							//������� ������� ������� ��������, ��������� ��� ������� ������ ����� ������� �������
							//������ ��� ����� �� ������ ����, ��������� �� �������� ���� �� ������ ����, ������� �� ��� �������
							//�� ������ ����� ��� ������ ����� �������� ��������� ������ ��������
							// b = 0 ������ ����� �����
							//������ �������� ������� �������, ��������� �� ���������� ������ ����� � ���� ������ ����, ���� ���� ����� ���������
							//���� ������ ������ ���������� b 
							//������ ����� ���� �����, �� �������� ������ ���������� ������

							if (stpr <= 0)
							{
								uppoint = 1;
							}
							if ((uppoint == 1) && (yp >= y))
							{
								uppoint = 0;
								jump = 0;
								stpr = 20;
							}
						}
						graphics->DrawImage(gameback, 0, 0);
						for (int i = 0; i < 10; i++){
							if ((((xp + 174) >= x[i]) && ((yp + 87) >= y) && (xp + 87 <= x[i])) || ((((xp + 87 - x[i])*(xp + 87 - x[i]) + (yp + 87 - y)*(yp + 87 - y)) <= 7569) && ((yp + 174) < y)))
							{
								lifes = lifes - 1;
								jump = 0;
								a = 0;
							}
							if ((((xp + 87) >= x[i]) && ((yp + 174) >= y)) && (xp <= x[i]))
							{
								padaet = 0;
								stpr = 1;
								yp = 304;
							}
							if (((xp - x[i])*(xp - x[i]) + (yp + 87 - y)*(yp + 87 - y)) <= 7569)
							{
								padaet = 0;
								stpr = 1;
							}
							x[i] = x[i] - 10;
							graphics->DrawImage(kirpich, x[i], y);
						}
						max = max - 10;
						xp = xp + j;
						Sleep(dif);
						graphics->DrawImage(packman, xp, yp);
						for (int i = 0; i < lifes; i++)
							graphics->DrawImage(life, (i * 131), 0);
						graphics->Flip();
					}





					//��������� ����� ��������� �� �����
					xp = xp + j;
					graphics->DrawImage(gameback, 0, 0);
					for (int i = 0; i < 10; i++)
					{
						x[i] = x[i] - 10;
						graphics->DrawImage(kirpich, x[i], y);
					}
					max = max - 10;
					Sleep(dif);
					for (int i = 0; i < lifes; i++)
						graphics->DrawImage(life, (i * 131), 0);
					graphics->DrawImage(packman, xp, yp);
					graphics->Flip();
					if (max <= 0)
					{
						cond = 2;
						a = 0;
					}
				}
			}
		}

		if (cond == 2)
		{

			if (input->IsMouseButtonDown(1))
			{
				// ����� ���������� ������� ������
				int x = input->GetButtonDownCoords().x / (GRID_SIZE_X / 4),
					y = input->GetButtonDownCoords().y / (GRID_SIZE_Y / 7);

				if (((x == 1) | (x == 2)) & (y == 1)) /*��������� ����*/
				{
					if (lvl == 5)
						cond = 3;
					if (lvl == 13)
						cond = 3;
					if ((lvl != 5) && (lvl != 13)){
						lvl = lvl + 1;
						cond = 1;
					}
				}
				if (((x == 1) | (x == 2)) & (y == 3))
				{
					cond = 1;
				}
				if (((x == 1) | (x == 2)) & (y == 5))
				{
					cond = 0;
					Sleep(100);
				}

			}
			graphics->DrawImage(pobeda, 0, 0);
			graphics->Flip();
			//���� 4-� �������� 
			//����� � ��������� ����
		}
		if (cond == 3)
		{
			graphics->DrawImage(titry, 0, 0);
			graphics->Flip();
			if (input->IsKeyDown(SDLK_ESCAPE))
				cond = 0;

		}
		//������ ��������
		if (cond == 4)
		{
			graphics->DrawImage(enh, 0, 0);
			graphics->Flip();
			if (input->IsMouseButtonDown(1))
			{
				// ����� ���������� ������� ������
				int x = input->GetButtonDownCoords().x,
					y = input->GetButtonDownCoords().y;

				// ���� �� ������ �� ������ ������
				if ((x >= 200) && (x <= 700) && (y >= 200) && (y <= 350)) /*��������� ����*/
				{
					dif = 10;
					while (!input->IsMouseButtonUp(1))
						input->Update();
					cond = 0;
				}
				if ((x >= 200) && (x <= 700) && (y >= 400) && (y <= 550)) /*��������� ����*/
				{
					dif = 8;
					while (!input->IsMouseButtonUp(1))
						input->Update();
					cond = 0;
				}
				if ((x >= 200) && (x <= 700) && (y >= 600) && (y <= 750)) /*��������� ����*/
				{
					dif = 6;
					while (!input->IsMouseButtonUp(1))
						input->Update();
					cond = 0;
				}
			}
		}

		if (cond == 5)
		{

		}

		//��������� ���������� �������
		if (cond == 7)
		{
			int kirpichi[10];
			int l = 0;
			int postavlen[10];
			for (int i = 0; i < 10; i++)
			{
				kirpichi[i] = 0;
				postavlen[i] = 0;
			}

			int b = 1;
			int a = 1;
			int x, y;
			int lvlch = 0;
			while (b)
			{
				graphics->DrawImage(levelchng, 0, 0);
				graphics->Flip();
				input->Update();
				if (input->IsMouseButtonDown(1))
				{
					x = input->GetButtonDownCoords().x,
						y = input->GetButtonDownCoords().y;
				}
				if ((y > 320) && (y < 448) && (x > 128) && (x < 256))
				{
					lvlch = 1;
					b = 0;
					a = 1;
				}
				if ((y > 320) && (y < 448) && (x > 258) && (x < 386))
				{
					lvlch = 2;
					b = 0;
					a = 1;
				}
				if ((y > 320) && (y < 448) && (x > 388) && (x < 516))
				{
					lvlch = 3;
					b = 0;
					a = 1;
				}

				if ((y > 667) && ((x / (GRID_SIZE_X / 8)) < 2))
				{
					cond = 0;
					a = 0;
					b = 0;
				}

			}
			while (a)
			{
				input->Update();
				graphics->DrawImage(gameback, 0, 0);
				if (input->IsMouseButtonDown(1))
				{
					x = input->GetButtonDownCoords().x,
						y = input->GetButtonDownCoords().y;
				}
				for (int i = 0; i < 10; i++)
				{
					if (postavlen[i] == 0)
						graphics->DrawImage(prozr, kirpichi[i], 627);
					else if ((postavlen != 0) && (kirpichi[i] != 0))
						graphics->DrawImage(kirp, kirpichi[i], 627);
				}

				if ((input->IsKeyDown('g')) && (postavlen[l] == 0))
					kirpichi[l] = kirpichi[l] + 1;
				if ((input->IsKeyDown('f')) && (postavlen[l] == 0))
					kirpichi[l] = kirpichi[l] - 1;
				if (input->IsKeyDown(SDLK_SPACE))
				{
					while (!input->IsKeyUp(SDLK_SPACE))
					{
						input->Update();
					}
					postavlen[l] = (postavlen[l] + 1) % 2;
				}
				for (int i = 0; i< 10; i++)
				{
					if ((x>kirpichi[i]) && (x < (kirpichi[i] + 10)) && (y < 650) && (y>620))
						l = i;
				}
				if (input->IsKeyDown(SDLK_ESCAPE))
					a = 0;
				graphics->Flip();
			}
			if (lvlch == 1)
			{
				FILE *f = fopen("C:\\Users\\user\\Desktop\\images\\lvls\\11.txt", "wb");
				for (int i = 0; i < 10; i++)
				{
					kirpichi[i] = kirpichi[i] * 8.7;
					if (postavlen[i] != 0)
						fprintf(f, "%d\r\n", kirpichi[i]);
				}
				fclose(f);
			}
			if (lvlch == 2)
			{
				FILE *f = fopen("C:\\Users\\user\\Desktop\\images\\lvls\\12.txt", "wb");
				for (int i = 0; i < 10; i++)
				{
					kirpichi[i] = kirpichi[i] * 8.7;
					if (postavlen[i] != 0)
						fprintf(f, "%d\r\n", kirpichi[i]);
				}
				fclose(f);
			}
			if (lvlch == 3)
			{
				FILE *f = fopen("C:\\Users\\user\\Desktop\\images\\lvls\\13.txt", "wb");
				for (int i = 0; i < 10; i++)
				{
					kirpichi[i] = kirpichi[i] * 8.7;
					if (postavlen[i] != 0)
						fprintf(f, "%d\r\n", kirpichi[i]);
				}
				fclose(f);
			}
			//����� ������� ��� ������������ 

			//������� ������ �������� ������� 
			//��� � �������� 

		}



		if (cond == 6)
		{
			graphics->DrawImage(levelback, 0, 0);
			graphics->Flip();
			if (input->IsMouseButtonDown(1))
			{
				int x = input->GetButtonDownCoords().x,
					y = input->GetButtonDownCoords().y;
				if ((y > 100) && (y < 228) && (x > 128) && (x < 256))
				{
					lvl = 1;
					cond = 1;
				}
				if ((y > 100) && (y < 228) && (x > 258) && (x < 386))
				{
					lvl = 2;
					cond = 1;
				}
				if ((y > 100) && (y < 228) && (x > 388) && (x < 516))
				{
					lvl = 3;
					cond = 1;
				}
				if ((y > 100) && (y < 228) && (x > 518) && (x < 646))
				{
					lvl = 4;
					cond = 1;
				}
				if ((y > 100) && (y < 228) && (x > 648) && (x < 776))
				{
					lvl = 5;
					cond = 1;
				}
				if ((y > 320) && (y < 448) && (x > 128) && (x < 256))
				{
					lvl = 11;
					cond = 1;
				}
				if ((y > 320) && (y < 448) && (x > 258) && (x < 386))
				{
					lvl = 12;
					cond = 1;
				}
				if ((y > 320) && (y < 448) && (x > 388) && (x < 516))
				{
					lvl = 13;
					cond = 1;
				}

				if ((y > 667) && ((x / (GRID_SIZE_X / 8)) < 2))
				{
					cond = 0;
				}

			}

		}
	}
};

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	Game game;
	return game.Execute(new TicTacToeScreen(), GRID_SIZE_X, GRID_SIZE_Y);
}