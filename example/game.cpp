#include "feather/core.h"
#include "feather/entity.h"
#include "feather/input.h"
#include "feather/text.h"
#include "feather/sound.h"
#include "feather/debug.h"
#include "feather/util.h"
#include "feather/vector.h"
#include "feather/rigidentity.h"

using namespace std;

Entity Player;
Entity Ball;

int speed = 2;
int ballSpeed = 1;

bool alive = true;

int score = 0;

bool down = true;
bool nleft = true;

void moveBall(){
	if(down){
		Ball.transform.position.y += ballSpeed;
	}
	else if(!down){
		Ball.transform.position.y -= ballSpeed;
	}

	if(nleft){
		Ball.transform.position.x += ballSpeed;
	}
	else if(!nleft){
		Ball.transform.position.x -= ballSpeed;
	}
}

void collideBall(){
	if(Ball.transform.position.x <= 0){
		nleft = true;
	}
	else if(Ball.transform.position.x >= 1830){
		nleft = false;
	}

	if(Ball.transform.position.y <= 0){
		down = true;
	}
	else if(Ball.transform.position.y >= 1000){
		down = false;
	}
}

void collidePlayer(){
	if(Player.transform.position.x <= 0){
		Player.transform.position.x = 0;
	}
	else if(Player.transform.position.x >= 1830){
		Player.transform.position.x = 1830;
	}

	if(Player.transform.position.y <= 0){
		Player.transform.position.y = 0;
	}
	else if(Player.transform.position.y >= 1000){
		Player.transform.position.y = 1000;
	}
}

//Runs on first frame
void Begin(){
	Player.Create("assets/player.png", 300, 300, 128, 128);
	Ball.Create("assets/ball.png", 800, 800, 128, 128);

	swapMusic("assets/song.mp3");
}

//Runs every frame
void Step(){
	if(isKeyHeld(Key_Up)){
		Player.transform.position.y -= speed;
	}
	if(isKeyHeld(Key_Down)){
		Player.transform.position.y += speed;
	}
	if(isKeyHeld(Key_Left)){
		Player.transform.position.x -= speed;
	}
	if(isKeyHeld(Key_Right)){
		Player.transform.position.x += speed;
	}

	if(alive){
		string scoreText = "Score: " + to_string(score);
		drawText(scoreText, 255, 255, 255, 255, Player.transform.position.x, Player.transform.position.y - 50);
	}

	if(alive){
		score += 1;
	}

	if(!alive){
		string finalText = "Game Over. Final Score: " + to_string(score);
		drawText(finalText, 255, 0, 0, 255, 0, 0);
	}

	if(score % 2000 == 0){
		ballSpeed += 1;
	}

	moveBall();
	collideBall();

	collidePlayer();

	if(Player.Collided(Ball) && Player.isActive()){
		Player.Destroy();
		alive = false;
		playSound("assets/destroy.wav");
	}
}

//Runs on last frame
void End(){
}
