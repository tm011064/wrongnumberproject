#include "AppDelegate.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

// If you want to use packages manager to install more packages, 
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("My Game");
        
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
        /*
        1536 x 2048: IPad HD (3:4)
        768  x 1280: Nexus 4 (5:8)
        720  x 1280: Galaxy SIII (9:16)
        640  x  960: IPhone 4 (2:3)
        640  x 1136: IPhone 5 (2:3)
        480  x  800: HTC Desire HD (3:5)
        320  x  480: IPhone (3:4)
        240  x  320: Various (3:4)
        */

        glview->setFrameSize(640, 1136);

        // 240 x 320, large
        // ----------------------------------------------------------
        // glview->setFrameSize(240, 320);   // Ratio = 3:4

        // 1536 x 2048, large
        // ----------------------------------------------------------
        // glview->setFrameSize(1536, 2048);   // Ratio = 3:4

        // 360 x 480, small
        // ----------------------------------------------------------
        // glview->setFrameSize(243, 324);   // Ratio = 3:4
        // glview->setFrameSize(182, 324);   // Ratio = 9:16
        // glview->setFrameSize(203, 324);   // Ratio = 5:8
        // glview->setFrameSize(194, 324);   // Ratio = 3:5
        // glview->setFrameSize(216, 324);   // Ratio = 2:3

        // 360 x 480, middle
        // ----------------------------------------------------------
        // glview->setFrameSize(300, 400);   // Ratio = 3:4
        // glview->setFrameSize(225, 400);   // Ratio = 9:16
        // glview->setFrameSize(250, 400);   // Ratio = 5:8
        // glview->setFrameSize(240, 400);   // Ratio = 3:5
        // glview->setFrameSize(267, 400);   // Ratio = 2:3

        // 360 x 480, large
        // ----------------------------------------------------------
        // glview->setFrameSize(360, 480);   // Ratio = 3:4
        // glview->setFrameSize(270, 480);   // Ratio = 9:16
        // glview->setFrameSize(300, 480);   // Ratio = 5:8
        // glview->setFrameSize(288, 480);   // Ratio = 3:5
        // glview->setFrameSize(320, 480);   // Ratio = 2:3




        // 720 x 960, small
        // ----------------------------------------------------------
        // glview->setFrameSize(375, 500);   // Ratio = 3:4
        // glview->setFrameSize(281, 500);   // Ratio = 9:16
        // glview->setFrameSize(312, 500);   // Ratio = 5:8
        // glview->setFrameSize(300, 500);   // Ratio = 3:5
        // glview->setFrameSize(333, 500);   // Ratio = 2:3

        // 720 x 960, medium
        // ----------------------------------------------------------
        // glview->setFrameSize(600, 800);   // Ratio = 3:4
        // glview->setFrameSize(450, 800);   // Ratio = 9:16
        // glview->setFrameSize(500, 800);   // Ratio = 5:8
        // glview->setFrameSize(480, 800);   // Ratio = 3:5
        // glview->setFrameSize(533, 800);   // Ratio = 2:3

        // 720 x 960, large
        // ----------------------------------------------------------
        // glview->setFrameSize(720, 960);   // Ratio = 3:4
        // glview->setFrameSize(540, 960);   // Ratio = 9:16
        // glview->setFrameSize(600, 960);   // Ratio = 5:8
        // glview->setFrameSize(576, 960);   // Ratio = 3:5
        // glview->setFrameSize(640, 960);   // Ratio = 2:3










        // 960 x 1280, small
        // ----------------------------------------------------------
        // glview->setFrameSize(735, 980);   // Ratio = 3:4    -> 0.75
        // glview->setFrameSize(551, 980);   // Ratio = 9:16   -> 0.5625
        // glview->setFrameSize(613, 980);   // Ratio = 5:8    -> 0.625
        // glview->setFrameSize(588, 980);   // Ratio = 3:5    -> 0.6
        // glview->setFrameSize(653, 980);   // Ratio = 2:3    -> 0.66

        // 960 x 1280, middle
        // ----------------------------------------------------------
        // glview->setFrameSize(840, 1120);   // Ratio = 3:4
        // glview->setFrameSize(630, 1120);   // Ratio = 9:16
        // glview->setFrameSize(700, 1120);   // Ratio = 5:8
        // glview->setFrameSize(672, 1120);   // Ratio = 3:5
        // glview->setFrameSize(747, 1120);   // Ratio = 2:3

        // 960 x 1280, large
        // ----------------------------------------------------------
        // glview->setFrameSize(960, 1280);   // Ratio = 3:4
        // glview->setFrameSize(720, 1280);   // Ratio = 9:16
        // glview->setFrameSize(800, 1280);   // Ratio = 5:8
        // glview->setFrameSize(768, 1280);   // Ratio = 3:5
        // glview->setFrameSize(853, 1280);   // Ratio = 2:3




        // glview->setFrameSize(720, 960);   // Ratio = 3:4
        // glview->setFrameSize(540, 960);   // Ratio = 9:16
        // glview->setFrameSize(600, 960);   // Ratio = 5:8
        // glview->setFrameSize(576, 960);   // Ratio = 3:5
        // glview->setFrameSize(640, 960);   // Ratio = 2:3

#endif

        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    register_all_packages();

    GameContext* gameContext = new GameContext();

    gameContext->setResolutionPolicy(ResolutionPolicy::NO_BORDER);
    gameContext->setOriginalSize(glview->getDesignResolutionSize()); // TODO (Roman): why do we need this???

    Size frameSize = glview->getFrameSize();
    
    gameContext->setResourceDefinition(SIZE_1536x2048);
    if (frameSize.width <= SIZE_960x1280.size.width
      && frameSize.height <= SIZE_960x1280.size.height)
    {
      gameContext->setResourceDefinition(SIZE_960x1280);
    }
    if (frameSize.width <= SIZE_720x960.size.width
      && frameSize.height <= SIZE_720x960.size.height)
    {
      gameContext->setResourceDefinition(SIZE_720x960);
    }
    if (frameSize.width <= SIZE_360x480.size.width
      && frameSize.height <= SIZE_360x480.size.height)
    {
      gameContext->setResourceDefinition(SIZE_360x480);
    }
    if (frameSize.width <= SIZE_240x320.size.width
      && frameSize.height <= SIZE_240x320.size.height)
    {
      gameContext->setResourceDefinition(SIZE_240x320);
    }

    // at the end, update the resolution size for the glview
    glview->setDesignResolutionSize(frameSize.width, frameSize.height, gameContext->getResolutionPolicy());

    NavigationManager::showScene(LOAD_GAME_SCENE, gameContext, FIRST_RUN, true);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
