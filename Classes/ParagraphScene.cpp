#include "ParagraphScene.h"
#include "tinyxml2/tinyxml2.h"
#include "MenuTextButton.h"
#include "NavigationManager.h"


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

  auto element = doc.RootElement();

  if (!element || std::strcmp(element->Name(), "paragraph") != 0)
  {
    CCLOG("Xml Error at '%s': wrong format -> paragraph tag not root element", filename.c_str());
    return false;
  }

  auto size = Director::getInstance()->getWinSize();
  element = element->FirstChildElement();
  while (element)
  {
    if (std::strcmp(element->Name(), "body") == 0)
    {
      auto textNodeElement = element->FirstChildElement();
      if (!textNodeElement || (std::strcmp(textNodeElement->Name(), "left") != 0 && std::strcmp(textNodeElement->Name(), "right") != 0))
      {
        CCLOG("Xml Error at '%s': wrong format -> left or right element expected in body", filename.c_str());
        return false;
      }

      auto scrollSize = Size(round(size.width), round(size.height*.75f));

      auto scrollView = ui::ScrollView::create();
      scrollView->setDirection(ui::ScrollView::Direction::VERTICAL);

      scrollView->setTouchEnabled(true);
      scrollView->setInertiaScrollEnabled(true);
      scrollView->setBounceEnabled(false);

      scrollView->setContentSize(scrollSize);
      scrollView->setAnchorPoint(Vec2(.5f, .5f));
      scrollView->setPosition(Vec2(round(scrollSize.width*.5f), round(size.height*.1f + scrollSize.height*.5f)));

      this->addChild(scrollView);

      float wrapWidth = round(GOLDEN_RATIO_PERCENTAGE*scrollSize.width);
      float leftPos = .0f;
      float rightPos = scrollSize.width - wrapWidth;
      float yPos = .0f;
      while (textNodeElement)
      {
        std::string text(textNodeElement->GetText());
        text = UtilityHelper::trim(text);

        auto label = LabelBMFont::create(text, m_pGameContext->getFontNormalPath(), wrapWidth);
        auto labelSize = label->getContentSize();

        if (std::strcmp(textNodeElement->Name(), "left") == 0)
        {
          label->setPosition(Vec2(round(leftPos + labelSize.width*.5f), round(yPos + labelSize.height + 12.0f)));
        }
        else if (std::strcmp(textNodeElement->Name(), "right") == 0)
        {
          label->setPosition(Vec2(round(rightPos + labelSize.width*.5f), round(yPos + labelSize.height + 12.0f)));
        }
        else
        {
          continue;
        }

        yPos = label->getPosition().y;

        scrollView->addChild(label);

        textNodeElement = textNodeElement->NextSiblingElement();
      }

      scrollView->setInnerContainerSize(Size(scrollSize.width, round(yPos + 50.0f)));
    }
    else if (std::strcmp(element->Name(), "choices") == 0)
    {
      float posY = round(m_pGameContext->getFontHeightNormal() / GOLDEN_RATIO_PERCENTAGE *.5f);
      float posX = round(size.width*.4f);
            
      auto choiceElement = element->FirstChildElement();
      while (choiceElement)
      {
        if (std::strcmp(choiceElement->Name(), "choice") == 0)
        {
          std::string text;
          std::string gotoPath;

          auto choiceBodyElement = choiceElement->FirstChildElement();
          while (choiceBodyElement)
          {
            if (std::strcmp(choiceBodyElement->Name(), "goto") == 0)
            {
              gotoPath = std::string(choiceBodyElement->GetText());
            }
            if (std::strcmp(choiceBodyElement->Name(), "text") == 0)
            {
              text = std::string(choiceBodyElement->GetText());
            }

            choiceBodyElement = choiceBodyElement->NextSiblingElement();
          }
          if (!text.empty() && !gotoPath.empty())
          {
            // TODO (Roman): create proper button with sizing
            auto choiceButton = MenuTextButton::create(m_pGameContext, text
              , MENU_BUTTON_TEXT_COLOR
              , MENU_BUTTON_BACKGROUND_COLOR
              , Size(size.width*.4f, m_pGameContext->getFontHeightNormal() / GOLDEN_RATIO_PERCENTAGE)
              );

            choiceButton->setPosition(Vec2(posX, posY));
            
            posX += round(size.width*.4f + 10.0f);

            choiceButton->addTouchEventListener([&,gotoPath](Ref* sender, Widget::TouchEventType type) {
              switch (type)
              {
              case ui::Widget::TouchEventType::BEGAN:
                break;
              case ui::Widget::TouchEventType::ENDED:                
                NavigationManager::showParagraph(m_pGameContext, gotoPath);
                break;
              default:
                break;
              }
            });
            
            this->addChild(choiceButton);
          }
        }

        choiceElement = choiceElement->NextSiblingElement();
      }
    }

    element = element->NextSiblingElement();
  }
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