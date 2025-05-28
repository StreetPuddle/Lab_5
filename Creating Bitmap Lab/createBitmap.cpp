#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>

struct arrow_class
{
	int x,y;
	int dir,speed;
	int color;

} arrow;

#define MAXSPEED 3

void create_arrow_bitmap(ALLEGRO_BITMAP * arrow_bmp[], ALLEGRO_DISPLAY *display);
/*
void erase_arrow();
void move_arrow();
void up();
void down();
void right();
void left();
*/

int main(void)
{

	ALLEGRO_BITMAP *arrow_bmp[4]={NULL,NULL,NULL,NULL};
	//variables
	int width = 640;
	int height = 480;
	bool done = false;

	//allegro variable
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;


	//program init
	if(!al_init())										//initialize Allegro
		return -1;

	display = al_create_display(width, height);			//create our display object

	if(!display)										//test display object
		return -1;

	//addon init
	al_install_keyboard();
	al_init_primitives_addon();
	create_arrow_bitmap(arrow_bmp, display);


	al_set_target_bitmap(al_get_backbuffer(display));
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_clear_to_color(al_map_rgb(0,0,0));
	al_flip_display();
	while(!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch(ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			}
		}


		al_draw_bitmap(arrow_bmp[0], width / 2, 100, 0);
		al_draw_bitmap(arrow_bmp[2], width / 2, 300, 0);
		al_draw_bitmap(arrow_bmp[3], width / 2, 400, 0);
		al_flip_display();
		al_clear_to_color(al_map_rgb(0,0,0));
	}
	for(int i=0; i<4; i++)
	{
		al_destroy_bitmap(arrow_bmp[i]);
	}
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);						//destroy our display object
	system("pause");
	return 0;
}

void create_arrow_bitmap(ALLEGRO_BITMAP * arrow_bmp[],ALLEGRO_DISPLAY *display)
{
	for(int i=0;i<4; i++)
	{
		arrow_bmp[i]=al_create_bitmap(64,64);   
		if(!arrow_bmp[i]) {
			exit(1);
			al_destroy_display(display);

		}

		al_set_target_bitmap(arrow_bmp[i]);
		al_clear_to_color(al_map_rgb(0, 0, 0));

		int x = 0, y = 0;

		al_draw_line(x + 16, y + 6, x + 32, y + 6, al_map_rgb(140, 140, 140), 4);
		al_draw_line(x + 16, y + 14, x + 38, y + 14, al_map_rgb(140, 140, 140), 4);
		al_draw_line(x + 16, y + 50, x + 38, y + 50, al_map_rgb(130, 130, 130), 4);
		al_draw_line(x + 16, y + 58, x + 32, y + 58, al_map_rgb(130, 130, 130), 4);
		al_draw_filled_triangle(x + 16, y, x + 40, y + 32, x + 16, y + 64, al_map_rgb(150, 150, 150));
		al_draw_filled_rectangle(x + 16, y, x + 8, y + 64, al_map_rgb(150, 150, 150));
		al_draw_filled_triangle(x, y + 18, x + 32, y + 32, x, y + 46, al_map_rgb(150, 150, 150));
		al_draw_filled_ellipse(x + 32, y + 32, x + 32, y + 9, al_map_rgb(160, 160, 160));
		al_draw_filled_ellipse(x + 48, y + 32, 8, 4, al_map_rgb(150, 150, 250));
	}
}


