//
//  SoundManager.h
//
//

#ifndef Test_SoundManager_h
#define Test_SoundManager_h

#include "SimpleAudioEngine.h"
#include "cocos2d.h"

using namespace cocos2d;

class SoundManager
{
public:
    static SoundManager& getInstance();
protected:
    explicit SoundManager();
    ~SoundManager();
private:
    void initSoundRes();
public:

    void playBackgroundMusic();
    
    void playErrorEffect();
    
    void PauseBackgroundMusic();
    void ResumeBackgroundMusic();
    void StopBackgroundMusic();

	void PauseAllSoundEffect();
	void ResumeAllSoundEffect();

};

#define g_SoundMgr SoundManager::getInstance()
/**
 *	播放音效
 *	@param	sid	音效ID
 */
void		PlaySoundEffect(const char* effectName);
/**
 *	暂停音效
 *	@param	sid	音效ID
 */
void		pauseSoundEffect(int sid);
/**
 *	停止音效
 *	@param	sid	音效ID
 */
void		StopSoundEffect(int sid);
/**
 *	停止一系列音效
 *	@param	count	id数量
 *	@param	sids	音效ID
 */
void		StopSoundEffects(int count,int* sids);
/**
 *	停止全部音效
 */
void		StopAllSoundEffect();
/**
 *	暂停全部音效
 */
void		PauseAllSoundEffect();
/**
 *	恢复全部音效
 */
void		ResumeAllSoundEffect();
/**
 *	设置音效音量
 *	@param	v	音量大小(0~1)
 */
void		SetSoundEffectVolume(float v);
/**
 *	获取音效音量
 */
float		GetSoundEffectVolume();
/**
 *	设置背景音乐音量
 *	@param	v	音量大小(0~1)
 */
void		SetBackgoundMusicVolume(float v);
/**
 *	获取背景音乐音量
 */
float		GetBackgoundMusicVolume();
/**
 *	检查iPod是否在播放
 *	@return true:播放 false:无
 */
bool		iPodIsPlaying();

#endif /* defined(Test_SoundManager_h) */
