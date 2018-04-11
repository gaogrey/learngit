//
//  SoundManager.cpp
//

#include "SoundManager.h"


using namespace CocosDenshion;

const char* csBgMusic = "Music/bg.mp3";
const char* csErrorMusic = "Music/error.mp3";



SoundManager& SoundManager::getInstance()
{
    static SoundManager obj;
    return obj;
}

SoundManager::SoundManager()
{
    initSoundRes();
}

SoundManager::~SoundManager()
{
    SimpleAudioEngine::getInstance()->end();
}

void SoundManager::initSoundRes()
{
    SimpleAudioEngine::getInstance()->preloadBackgroundMusic(csBgMusic);
    
    
    SimpleAudioEngine::getInstance()->preloadEffect(csErrorMusic);
    

}


void SoundManager::playBackgroundMusic()
{
    SimpleAudioEngine::getInstance()->playBackgroundMusic(csBgMusic, true);
}



void SoundManager::playErrorEffect()
{
    SimpleAudioEngine::getInstance()->playEffect(csErrorMusic);
}

void SoundManager::PauseBackgroundMusic()
{
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

void SoundManager::ResumeBackgroundMusic()
{
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

void SoundManager::PauseAllSoundEffect()
{
    SimpleAudioEngine::getInstance()->pauseAllEffects();
}

void SoundManager::ResumeAllSoundEffect()
{
    SimpleAudioEngine::getInstance()->resumeAllEffects();
}

void SoundManager::StopBackgroundMusic()
{
    SimpleAudioEngine::getInstance()->stopBackgroundMusic();
}


/**
 *	播放背景音乐
 *	@param	musicName	音乐名称
 *	@param	bLoop		是否循环
 */
void PlayBackgroundMusic(const char* musicName,bool bLoop)
{
    if (musicName != nullptr) {
        SimpleAudioEngine::getInstance()->playBackgroundMusic(musicName, bLoop);
    }
}
/**
 *	暂停背景音乐
 */
void PauseBackgroundMusic()
{
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}
/**
 *	继续背景音乐
 */
void ResumeBackgroundMusic()
{
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
/**
 *	停止背景音乐
 */
void StopBackgroundMusic()
{
    SimpleAudioEngine::getInstance()->stopBackgroundMusic();
}
/**
 *	加载音效
 *	@param	effectName	音效名称
 *	@return	返回音效ID，以后通过这个ID操作音效
 */
void LoadSoundEffect(const char* effectName)
{
    if (effectName != nullptr) {
        SimpleAudioEngine::getInstance()->preloadEffect(effectName);
    }
}
/**
 *	卸载音效
 *	@param	sid	音效ID
 */
void UnloadSoundEffect(const char* effectName)
{
    SimpleAudioEngine::getInstance()->unloadEffect(0);
}
/**
 *	卸载全部音效
 */
void UnloadAllSoundEffect()
{
}
/**
 *	播放音效
 *	@param	sid	音效ID
 */
void PlaySoundEffect(const char* effectName)
{
    SimpleAudioEngine::getInstance()->playEffect(effectName);
}
/**
 *	暂停音效
 *	@param	sid	音效ID
 */
void pauseSoundEffect(int sid)
{
    SimpleAudioEngine::getInstance()->pauseEffect(sid);
}
/**
 *	停止音效
 *	@param	sid	音效ID
 */
void StopSoundEffect(int sid)
{
    SimpleAudioEngine::getInstance()->stopEffect(sid);
}
/**
 *	停止一系列音效
 *	@param	count	id数量
 *	@param	sids	音效ID
 */
void StopSoundEffects(int count,int* sids)
{
}
/**
 *	停止全部音效
 */
void StopAllSoundEffect()
{
    SimpleAudioEngine::getInstance()->stopAllEffects();
}
/**
 *	暂停全部音效
 */
void PauseAllSoundEffect()
{
    SimpleAudioEngine::getInstance()->pauseAllEffects();
}
/**
 *	恢复全部音效
 */
void ResumeAllSoundEffect()
{
    SimpleAudioEngine::getInstance()->resumeAllEffects();
}
/**
 *	设置音效音量
 *	@param	v	音量大小(0~1)
 */
void SetSoundEffectVolume(float v)
{
    SimpleAudioEngine::getInstance()->setEffectsVolume(v/100);
}
/**
 *	获取音效音量
 */
float GetSoundEffectVolume()
{
    return SimpleAudioEngine::getInstance()->getEffectsVolume();
}
/**
 *	设置背景音乐音量
 *	@param	v	音量大小(0~1)
 */
void SetBackgoundMusicVolume(float v)
{
    SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(v/100);
}
/**
 *	获取背景音乐音量
 */
float GetBackgoundMusicVolume()
{
    return SimpleAudioEngine::getInstance()->getBackgroundMusicVolume();
}
/**
 *	检查iPod是否在播放
 *	@return true:播放 false:无
 */
bool iPodIsPlaying()
{
    return SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying();
}

//test