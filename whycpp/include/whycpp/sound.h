#ifndef WHYCPP_SOUND_H_
#define WHYCPP_SOUND_H_

#include <string>

/**
* @defgroup Sound
* @ingroup WHYCPP_PublicAPI
* @brief Functions to play some sound and music
* @details You need sdl2_mixer library to be installed. https://www.libsdl.org/projects/SDL_mixer/
* @{
*/

/**
 * Loads audio file in memory. Setup an association between sound and name.
 * @param path Music file path
 * @param name Name to reference this music from the PlayMusic() function
 */
void ImportMusic(const std::string &path, const std::string &name);
/**
 * Loads audio file in memory. Setup an association between sound and name.
 * @param path Sound effect file path
 * @param name Name to reference this sound effect from the PlaySFX() function
 */
void ImportSFX(const std::string &path, const std::string &name);
/**
 *
 * @param name Name of the music to play.
 * @param loops Number of loops, -1 is infinite loops. Passing one here plays the sample twice (1 loop).
 */
void PlayMusic(const std::string &name, int loops = -1);
/**
 *
 * @param name Name of the music to play.
 * @param loops Number of loops, -1 is infinite loops. Passing one here plays the sample twice (1 loop).
 * @param ticks Millisecond limit to play sample, at most. If not enough loops or the sample chunk is not long enough,
 * then the sample may stop before this timeout occurs. -1 means play forever.
 */
void PlaySFX(const std::string &name, int loops = 0, int ticks = -1);
/**
 * Stop the music. Next PlayMusic call starts playing from the beginning.
 * @param name unique music name which was set by ImportMusic
 */
void StopMusic(const std::string &name);
/**
 * Stop the sound effect. Next PlaySFX call starts playing from the beginning.
 * @param name unique sound effect name which was set by ImportSFX
 */
void StopSFX(const std::string &name);

/** @} */

#endif  // WHYCPP_SOUND_H_
