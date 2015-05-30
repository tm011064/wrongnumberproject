#include "BaseFileUtils.h"

std::vector<std::string> BaseFileUtils::getNumberedKeys(ValueMap &valueMap, const std::string &key)
{
  auto fileUtils = FileUtils::getInstance();
  std::vector<std::string> list;

  for (auto it = valueMap.begin(); it != valueMap.end(); ++it)
  {
    std::string k = it->first;// .c_str();

    //std::string s = it->second.asString();
    if (k.length() >= key.length()
      && k.substr(0, key.length()) == key)
    {
      list.push_back(k);
    }
  }

  return list;
}

//std::vector<std::string> BaseFileUtils::getNumberedResourceFiles(const std::string &fileName, const std::string &key)
//{
//  std::vector<std::string> list;
//
//  CCArray* keys = this->m_pFilenameLookupDict->allKeys();
//
//  std::string keyString = std::string(key);
//  Object* o;
//  std::string s;
//
//  CCARRAY_FOREACH(keys, o)
//  {
//    s = std::string(((CCString*)o)->getCString());
//    if (s.length() >= keyString.length()
//      && s.substr(0, keyString.length()) == keyString)
//    {
//      list.push_back(((CCString*)this->m_pFilenameLookupDict->objectForKey(s))->getCString());
//    }
//  }
//  o = NULL;
//  keys = NULL;
//
//  return list;
//}
//
//std::string BaseFileUtils::valueForKey(const std::string &key)
//{
//  CCString* s = (CCString*)this->m_pFilenameLookupDict->objectForKey(key);
//  if (s != NULL)
//  {
//    return s->getCString();
//  }
//}