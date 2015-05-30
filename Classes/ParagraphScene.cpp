#include "ParagraphScene.h"
#include "tinyxml2/tinyxml2.h"


void ParagraphScene::onEscapeKeyPressed()
{
  // TODO (Roman): react
}

ParagraphScene* ParagraphScene::create(GameContext* gameContext, const std::string& filename)
{
  ParagraphScene *ret = new (std::nothrow) ParagraphScene(gameContext);
  if (ret && ret->init(filename))
  {
    ret->autorelease();
    return ret;
  }
  else
  {
    CC_SAFE_DELETE(ret);
    return nullptr;
  }
}

bool ParagraphScene::parseXml(const std::string& filename)
{
  auto fileUtils = FileUtils::getInstance();

  // TODO (Roman): parse xml, try/catch
  const std::string fullPath = FileUtils::getInstance()->fullPathForFilename(filename);

  tinyxml2::XMLDocument doc;

  ssize_t buffer_size = 0;
  unsigned char* file_buffer = FileUtils::getInstance()->getFileData(fullPath, "r", &buffer_size);

  doc.Parse((const char*)file_buffer, buffer_size);

  tinyxml2::XMLElement *element = doc.RootElement();

  if (!element || std::strcmp(element->Name(), "paragraph") != 0)
  {
    CCLOG("Xml Error at '%s': wrong format -> paragraph tag not root element", filename);
    return false;
  }

  element = element->FirstChildElement();
  if (!element || std::strcmp(element->Name(), "body") != 0)
  {
    CCLOG("Xml Error at '%s': wrong format -> body element expected", filename);
    return false;
  }

  element = element->FirstChildElement();
  if (!element || (std::strcmp(element->Name(), "left") != 0 && std::strcmp(element->Name(), "right") != 0))
  {
    CCLOG("Xml Error at '%s': wrong format -> left or right element expected in body", filename);
    return false;
  }

  auto size = Director::getInstance()->getWinSize();
  auto scrollSize = Size(round(size.width), round(size.height*.75f));

  auto scrollView = ui::ScrollView::create();
  scrollView->setDirection(ui::ScrollView::Direction::VERTICAL);
    
  scrollView->setTouchEnabled(true);
  scrollView->setInertiaScrollEnabled(true);
  scrollView->setBounceEnabled(false);
  
  scrollView->setContentSize(scrollSize);
  scrollView->setAnchorPoint(Vec2(.5f,.5f));
  scrollView->setPosition(Vec2(round(scrollSize.width*.5f), round(size.height*.1f + scrollSize.height*.5f)));
  
  this->addChild(scrollView);

  float wrapWidth = round(GOLDEN_RATIO_PERCENTAGE*scrollSize.width);
  float leftPos = .0f;
  float rightPos = scrollSize.width - wrapWidth;
  float yPos = .0f;
  while (element)
  {
    std::string text(element->GetText());
    text = UtilityHelper::trim(text);
    
    auto label = LabelBMFont::create(text, m_pGameContext->getFontNormalPath(), wrapWidth);
    auto labelSize = label->getContentSize();
    
    if (std::strcmp(element->Name(), "left") == 0)
    {
      label->setPosition(Vec2(round(leftPos + labelSize.width*.5f), round(yPos + labelSize.height + 12.0f)));
    }
    else
    {
      label->setPosition(Vec2(round(rightPos + labelSize.width*.5f), round(yPos + labelSize.height + 12.0f)));
    }

      yPos = label->getPosition().y;

    scrollView->addChild(label);    

    element = element->NextSiblingElement();

  }

  scrollView->setInnerContainerSize(Size(scrollSize.width, round(yPos + 50.0f)));
}


bool ParagraphScene::init(const std::string& filename)
{
  if (!Scene::init())
    return false;

  parseXml(filename);

  return true;
}

void ParagraphScene::onEnter()
{
  Scene::onEnter();

  if (!m_isLayoutInitialized)
  {
    m_isLayoutInitialized = true;

    
  }
}