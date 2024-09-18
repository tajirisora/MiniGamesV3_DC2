#pragma once
#include "GAME_OBJECT.h"
#include "NOTE.h"
#include <vector>
#include <string>

namespace GAME09 {
    class RHYTHM_GAME_CONTROLLER :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            float rawSpeed;
            float BeforePlayTime;
            float detailViewTime;
            float detailViewDisappearTime;
        };
        enum STATE {
            DETAIL_VIEW,
            BEFORE_PLAY,
            PLAY,
            AFTER_PLAY
        };
        struct CHANGEDATA {
            double time;
            double visualBeat;
            double bpm;
            VECTOR2 measure;
        };
    private:
        DATA RGCont;
        //std::vector<NOTE*> Notes;
        //std::vector<CHANGEDATA> ChangeDatas;
        //SONGINFO SongInfo;
        //std::vector<INPUT_CODE> KeyConfig;
        int AllNotesNum;

        double BPM;
        VECTOR2 Measure;
        double Offset;
        double TempTime;       //bpmなどが変わったときにその時点の時間を記録しておく
        double CurTime;        //現在の時間
        double TempVisualBeat; //bpmなどが変わったときにその時点の見た目上の拍数を記録しておく
        double VisualBeat;     //現在の見た目上の拍数
        double EndTime;        //最後のノーツの時間

        STATE State;
        bool Finish = false;
        float AnimeTime;

        float Speed = 11.3f;

        bool Auto = true;
    public:
        RHYTHM_GAME_CONTROLLER(class GAME* game);
        ~RHYTHM_GAME_CONTROLLER();
        void create();
        void init();
        void update();
        void draw();

        double curTime() { return CurTime; }
        double visualBeat() { return VisualBeat; }
        float speed() { return Speed; }
        float rawSpeed() { return RGCont.rawSpeed; }
        bool isChangeScene() { return Finish; }
        bool isPlay() { return State == PLAY; }
        float* speedPtr() { return &Speed; }
        bool* autoPtr() { return &Auto; }
    };
}