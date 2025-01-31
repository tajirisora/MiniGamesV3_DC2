#include"../../libOne/inc/graphic.h"
#include "../../libOne/inc/sound.h"
#include "CONTAINER.h"
#include"ANIMS.h"
#include"GAME03.h"
#include<time.h>
namespace GAME03 {
    CONTAINER::~CONTAINER() {

        delete Data.playerChara1.anims;
        delete Data.playerChara2.anims;
        delete Data.playerChara3.anims;
        delete Data.playerChara4.anims;
        delete Data.playerChara5.anims;

        delete Data.enemyChara1.anims;
        delete Data.enemyChara2.anims;
        delete Data.enemyChara3.anims;
        delete Data.enemyChara4.anims;

    }
    void CONTAINER::load() {
        CreateData();
        LoadGraphics();
        LoadBgms();
    }
    void CONTAINER::CreateData() {

        Data.stage.backToTitleTime = 2;
        Data.stage.gameOverColor = COLOR(255, 0, 0);
        Data.stage.stageClearColor = COLOR(255, 255, 0);
        Data.stage.logoPx = (width - 800) / 2;
        Data.stage.logoPy = (height - 400) / 2;

        Data.map.chipSize = 50;
        Data.map.centerX = width / 2.0f - Data.map.chipSize / 2.0f;

        Data.fade.color = COLOR(60, 60, 60);
        Data.fade.speed = 255 * 2;

        Data.select.TimePls = 0;

        Data.volume.backColor = COLOR(255, 255, 255, 255);


        Data.charaMng.numPlayers = 1;
        Data.charaMng.numPlayerBullets = 10;
        Data.charaMng.numBats = 100;


        Data.playerChara1.charaId = MAP::PLAYER1_ID;
        Data.playerChara1.hp = 50;
        Data.playerChara1.groupId = 0;
        Data.playerChara1.speed = 4.6f * 60;
        Data.playerChara1.offsetLeft = 10.0f;
        Data.playerChara1.offsetTop = 1.0f;
        Data.playerChara1.offsetRight = 40.0f;
        Data.playerChara1.offsetBottom = 49.0f;
        Data.player.damageColor = COLOR(255, 0, 0);
        Data.player.normalColor = COLOR(255, 255, 255);
        Data.player.damageTime = 0;
        Data.player.damageInterval = 5 * 0.016f;
        Data.player.rightAnimId = 0;
        Data.player.leftAnimId = 1;
        Data.player.initVecUp = -16.0f;
        Data.player.initVecDown = 3.0f;
        Data.player.bulletOffsetX = 20.0f;
        Data.player.bulletOffsetY = 20.0f;
        Data.player.bulletCharaId = MAP::PLAYER_BULLET_ID;

        Data.playerBulletChara.charaId = MAP::PLAYER_BULLET_ID;
        Data.playerBulletChara.groupId = 0;
        Data.playerBulletChara.hp = 1;
        Data.playerBulletChara.speed = 6.9f * 60;
        Data.playerBulletChara.offsetLeft = 20.0f;
        Data.playerBulletChara.offsetTop = 20.0f;
        Data.playerBulletChara.offsetRight = 30.0f;
        Data.playerBulletChara.offsetBottom = 30.0f;

        Data.enemyChara1.charaId = MAP::BAT_ID;
        Data.enemyChara1.groupId = 1;
        Data.enemyChara1.hp = 50;
        Data.enemyChara1.speed = 2.5f * 60;
        Data.enemyChara1.offsetLeft = 10.0f;
        Data.enemyChara1.offsetTop = 10.0f;
        Data.enemyChara1.offsetRight = 30.0f;
        Data.enemyChara1.offsetBottom = 35.0f;
        Data.enemy.damageTime = 0;
        Data.enemy.damageInterval = 5 * 0.016f;
        Data.enemy.damageColor = COLOR(255, 0, 0);
        Data.enemy.normalColor = COLOR(255, 255, 255);
        Data.enemy.rightAnimId = 0;
        Data.enemy.leftAnimId = 1;
        Data.enemy.initVecUp = -16.0f;
        Data.enemy.initVecDown = 3.0f;

        Data.select.numPlayer = 0;
        Data.select.numStage = 0;
        Data.select.deterPlayer = 0;
        Data.select.deterStage = 0;
        Data.select.Confirm_selection = false;
        Data.select.click_cnt = 0;
        Data.select.a = 0;
        Data.select.b = 0;
        Data.select.next_scene = false;
        Data.select.targetPath = "..\\main\\assets\\game03\\data\\player";

    }
    void CONTAINER::LoadGraphics() {
        Data.stage.masterImg = loadImage("..\\main\\assets\\game03\\data\\achievements\\.png");
        Data.stage.stageClearImg = loadImage("..\\main\\assets\\game03\\data\\StageClear.png");
        Data.stage.gameOverImg = loadImage("..\\main\\assets\\game03\\data\\GameOver.png");
        Data.stage.backImg = loadImage("..\\main\\assets\\game03\\data\\back_Img.png");
        Data.stage.backTitleImg = loadImage("..\\main\\assets\\game03\\data\\再開.png");
        Data.stage.restartImg = loadImage("..\\main\\assets\\game03\\data\\タイトルに戻る.png");
        Data.stage.playStopImg = loadImage("..\\main\\assets\\game03\\data\\play_stp.png");
        Data.stage.playStopButtonImg = loadImage("..\\main\\assets\\game03\\data\\play_stp_buttonImg.png");
        Data.stage.forestImg = loadImage("..\\main\\assets\\game03\\data\\BrightForest-A2.png");
        Data.stage.forestImg = cutImage(Data.stage.forestImg, 0, 0, 65, 95);

        Data.playerBulletChara.img = loadImage("..\\main\\assets\\game03\\data\\playerBullet.png");

        Data.explan.explanationImg = loadImage("..\\main\\assets\\game03\\data\\操作説明.png");

        Data.map.blockImg = loadImage("..\\main\\assets\\game03\\data\\block.png");

        Data.select.select_cfream = loadImage("..\\main\\assets\\game03\\data\\select_chara_fream.png");
        Data.select.select_sfream = loadImage("..\\main\\assets\\game03\\data\\select_stage_fream.png");
        Data.select.select_chara = loadImage("..\\main\\assets\\game03\\data\\select_chara.png");
        Data.select.select_stage = loadImage("..\\main\\assets\\game03\\data\\select_stage.png");

        char filename[64]{};
        for (int i = 0; i < 5; i++) {
            sprintf_s(filename, "..\\main\\assets\\game03\\data\\player\\Player%d", i + 1);
            switch (i + 1) {
            case(1):
                Data.playerChara1.anims = new ANIMS(filename);
                break;
            case(2):
                Data.playerChara2.anims = new ANIMS(filename);
                break;
            case(3):
                Data.playerChara3.anims = new ANIMS(filename);
                break;
            case(4):
                Data.playerChara4.anims = new ANIMS(filename);
                break;
            case(5):
                Data.playerChara5.anims = new ANIMS(filename);
                break;
            }
        }
        for (int i = 0; i < 4; i++) {
            sprintf_s(filename, "..\\main\\assets\\game03\\data\\enemy\\Enemy%d", i + 1);
            switch (i + 1) {
            case(1):
                Data.enemyChara1.anims = new ANIMS(filename);
                break;
            case(2):
                Data.enemyChara2.anims = new ANIMS(filename);
                break;
            case(3):
                Data.enemyChara3.anims = new ANIMS(filename);
                break;
            case(4):
                Data.enemyChara4.anims = new ANIMS(filename);
                break;
            }
        }
        for (int i = 0; i < 5; i++) {
            sprintf_s(filename, "..\\main\\assets\\game03\\data\\player\\Player%d\\1\\playerL00.png", i + 1);
            Data.select.chara_img[i] = loadImage(filename);
        }
    }

    void CONTAINER::LoadBgms() {
        Data.volume.Snd_A = loadSound("..\\main\\assets\\game03\\data\\sounds\\y020.wav");
        Data.volume.Snd_B = loadSound("..\\main\\assets\\game03\\data\\sounds\\Noesis_2.wav");
        Data.volume.Snd_C;// = loadSound("..\\main\\assets\\game03\\data\\sounds\\.wav");
        Data.volume.Snd_D;// = loadSound("..\\main\\assets\\game03\\data\\sounds\\.wav");

        Data.volume.Se_A = loadSound("..\\main\\assets\\game03\\data\\sounds\\damage.wav");
        Data.volume.Se_B = loadSound("..\\main\\assets\\game03\\data\\sounds\\died.wav");
        Data.volume.Se_C = loadSound("..\\main\\assets\\game03\\data\\sounds\\switch_task.wav");
        Data.volume.Se_D = loadSound("..\\main\\assets\\game03\\data\\sounds\\close_win.wav");
        Data.volume.Se_E = loadSound("..\\main\\assets\\game03\\data\\sounds\\open_win.wav");
        Data.volume.Se_F = loadSound("..\\main\\assets\\game03\\data\\sounds\\Clear.wav");

        Data.volume.volume1 = 80.0f;
        Data.volume.volume2 = 80.0f;

        setVolume(Data.volume.Snd_A, -(100 - (int)Data.volume.volume1) * (100 - (int)Data.volume.volume1));
        setVolume(Data.volume.Snd_B, -(100 - (int)Data.volume.volume1) * (100 - (int)Data.volume.volume1));
        setVolume(Data.volume.Snd_C, -(100 - (int)Data.volume.volume1) * (100 - (int)Data.volume.volume1));
        setVolume(Data.volume.Se_A, -(100 - (int)Data.volume.volume2) * (100 - (int)Data.volume.volume2));
        setVolume(Data.volume.Se_B, -(100 - (int)Data.volume.volume2) * (100 - (int)Data.volume.volume2));
        setVolume(Data.volume.Se_C, -(100 - (int)Data.volume.volume2) * (100 - (int)Data.volume.volume2));
    }
}