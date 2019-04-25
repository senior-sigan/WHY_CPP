#ifndef WHYCPP_SOUND_H_
#define WHYCPP_SOUND_H_

#include <string>

class Context;

/**
 * Loads audio file in memory. Setup an association between sound and name.
 * @param path Music file path
 * @param name Name to reference this music from the PlayMusic() function
 */
void ImportMusic(Context &context, const std::string &path, const std::string &name);
/**
 * Loads audio file in memory. Setup an association between sound and name.
 * @param path Sound effect file path
 * @param name Name to reference this sound effect from the PlaySFX() function
 */
void ImportSFX(Context &context, const std::string &path, const std::string &name);
/**
 *
 * @param name Name of the music to play.
 * @param loops Number of loops, -1 is infinite loops. Passing one here plays the sample twice (1 loop).
 */
void PlayMusic(const Context &context, const std::string &name, int loops = -1);
/**
 *
 * @param name Name of the music to play.
 * @param loops Number of loops, -1 is infinite loops. Passing one here plays the sample twice (1 loop).
 * @param ticks Millisecond limit to play sample, at most. If not enough loops or the sample chunk is not long enough,
 * then the sample may stop before this timeout occurs. -1 means play forever.
 */
void PlaySFX(const Context &context, const std::string &name, int loops = 0, int ticks = -1);

#endif  // WHYCPP_SOUND_H_
