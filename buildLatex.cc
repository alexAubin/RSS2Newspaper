
#include <iostream>
#include <string>

#include "tinyxml/tinyxml.h"

using namespace std;

void printArticle(string source, string date, string hour, string title, string content, string id);

int main(int argc, char** argv)
{

  TiXmlDocument* doc;
  TiXmlHandle* hdl;
  TiXmlNode *node; 
  TiXmlElement *elem;
 
  // Load the XML file
  doc = new TiXmlDocument("data.xml");
  if (!doc->LoadFile ())
  {
	  cerr << "Error while loading the xml file" << endl;
  	  return -1;
  }

  // Get the node "Articles"
  hdl  = new TiXmlHandle (&(*doc));
  node = hdl->Node();
  string nodeName("Articles");
  for( node = node->FirstChild(); node; node = node->NextSibling() )
      if (node->Value () == string (nodeName)) break;
 
  // Get first elemenent
  elem = node->FirstChildElement ();
  if(!elem) 
  {
	  cerr << "No node Articles, or Articles empty." << endl;
	  return -1; 
  }
  while (elem)
  {
	int interestFlag = 0;	
	elem->QueryIntAttribute ("interestFlag", &interestFlag);

	if (interestFlag)
	{
		// Get data
		string source    = elem->Attribute("source");
		string date      = elem->Attribute("date");
		string hour      = elem->Attribute("hour");
		string title     = elem->Attribute("title");
		string content   = elem->Attribute("content");
		string id        = elem->Attribute("id");

		printArticle(source,date,hour,title,content,id);
	}

	// Next elem
	elem = elem->NextSiblingElement();
  }

}

void printArticle(string source, string date, string hour, string title, string content, string id)
{
    cout << "\\printArticle"       << endl;
	cout << "{" << title  << "}"   << endl;
	cout << "{" << content  << "}" << endl;
	cout << "{" << source  << "}"  << endl;
	cout << "{" << date  << "}"    << endl;
	cout << "{" << hour  << "}"    << endl;
	cout << "{(" << id  << ")}"    << endl;
}
