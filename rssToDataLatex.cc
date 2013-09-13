
#include <iostream>
#include <string>

#include "tinyxml/tinyxml.h"

using namespace std;

int main(int argc, char** argv)
{

  TiXmlDocument* doc;
  TiXmlHandle* hdl;
  TiXmlNode *node; 
  TiXmlElement *item;
  TiXmlElement *data;
 
  // Load the XML file
  doc = new TiXmlDocument("rssinput.xml");
  if (!doc->LoadFile ())
  {
	  cerr << "Error while loading the xml file" << endl;
  	  return -1;
  }
  hdl  = new TiXmlHandle (&(*doc));

  // Get the node "rss/channel"
  
  node = hdl->Node();
  for( node = node->FirstChild() ; node ; node = node->NextSibling() )
      if (node->Value() == string("rss")) break;
  for( node = node->FirstChildElement() ; node ; node = node->NextSiblingElement() )
 	  if (node->Value() == string("channel")) break;


  // Loop on "item"s
  for ( item = node->FirstChildElement() ;
		item ; 
		item = item->NextSiblingElement() )
  {
     if (item->Value() != string("item")) continue;
	
	 cout << "<a" << endl;
	 cout << "	source=\"Slashdot\"" << endl;
	 cout << "	date=\"01/01/1970\"" << endl;
	 cout << "	hour=\"13:37\"" << endl;
 
	 for (data = item->FirstChildElement() ;
		  data ;
		  data = data->NextSiblingElement())
	 {
     	 if ((data->Value() != string("title"))
		  && (data->Value() != string("description")))
	     continue;

     	 if (data->Value() == string("title"))
		 	cout << "	title=\"" << data->GetText() << "\"" << endl;
		 else if  (data->Value() == string("description"))
		 {
			 string description(data->GetText());
			 description.resize(description.find("<p>"));
			 cout << "	content=\"" << description << "\"" << endl;
		 }
	 }
	cout << "	id=\"s001\"" << endl;
	cout << "	interestFlag=\"1\"" << endl;
	cout << "/>" << endl;
  }
}
