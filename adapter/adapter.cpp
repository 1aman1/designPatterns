#include <iostream>

// target interface 
class IMediaPlayer
{
public:
    virtual void play(const std::string &songName) = 0;
};

// adaptee interface 
class IAdvancedMediaPlayer
{
public:
    virtual void playAvi(const std::string &songName) = 0;
    virtual void playMp4(const std::string &songName) = 0;
};

// adaptee  concrete
// avi
class AviPlayer : public IAdvancedMediaPlayer
{
public:
    void playAvi(const std::string &songName) override
    {
        std::cout << "Playing AVI file: " << songName << std::endl;
    }

    void playMp4(const std::string &songName) override
    {
        // unsupported
    }
};

// mp4
class Mp4Player : public IAdvancedMediaPlayer
{
public:
    void playAvi(const std::string &songName) override
    {
        // unsupported
    }

    void playMp4(const std::string &songName) override
    {
        std::cout << "Playing MP4 file: " << songName << std::endl;
    }
};

// adapter class
class MediaPlayerAdapter : public IMediaPlayer
{
    IAdvancedMediaPlayer *advancedPlayer_ = nullptr;

public:
    MediaPlayerAdapter(const std::string &fileFormat)
    {
        if (fileFormat == "mp4")
        {
            advancedPlayer_ = new Mp4Player();
        }
        else if (fileFormat == "avi")
        {
            advancedPlayer_ = new AviPlayer();
        }
        else
        {
            std::cout << "unsupported file format\n";
            advancedPlayer_ = nullptr;
        }
    }

    void play(const std::string &songName) override
    {
        if (advancedPlayer_ != nullptr)
        {
            if (songName.substr(songName.find_last_of(".") + 1) == "mp4")
                advancedPlayer_->playMp4(songName);
            else if (songName.substr(songName.find_last_of(".") + 1) == "avi")
                advancedPlayer_->playAvi(songName);
            else
            {
                std::cout << "unservable request\n";
            }
        }
    }
};

int main()
{
    IMediaPlayer *player = new MediaPlayerAdapter("mp4");
    player->play("boulevard of broken dreams.mp4");

    delete player;

    return 0;
}

/* The IMediaPlayer class represents the Target or desired interface, which defines the play() method that the client code needs to use.

The IAdvancedMediaPlayer class represents the Adaptee interface or legacy code, which defines methods for playing specific types of media files (MP4 and AVI in this case).

The Mp4Player and AviPlayer classes are concrete implementations of the IAdvancedMediaPlayer interface.

The MediaPlayerAdapter class is the Adapter, which implements the IMediaPlayer interface. It internally uses an instance of the IAdvancedMediaPlayer interface (either Mp4Player or AviPlayer) to perform the appropriate operations based on the file type.

In the main() function, there is basic usage of the Adapter pattern. The MediaPlayerAdapter is created with the file type "mp4", which internally uses the Mp4Player to play the MP4 file "movie.mp4".
 */
