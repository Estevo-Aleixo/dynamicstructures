#ifndef SOUNDHANDLER_H
#define SOUNDHANDLER_H

#include <Phonon/AudioOutput>
#include <Phonon/SeekSlider>
#include <Phonon/MediaObject>
#include <Phonon/VolumeSlider>
#include <Phonon/BackendCapabilities>



class SoundHandler
{
public:
    SoundHandler();

     Phonon::SeekSlider *seekSlider;
     Phonon::MediaObject *mediaObject;
     Phonon::MediaObject *metaInformationResolver;
     Phonon::AudioOutput *audioOutput;
     Phonon::VolumeSlider *volumeSlider;
    // QList<Phonon::MediaSource> sources;


};

#endif // SOUNDHANDLER_H
