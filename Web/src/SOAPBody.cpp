//
// SOAPBody.cpp
//
// $Id: //poco/1.1.0/XML/src/SOAPBody.cpp#1 $
//
// Library: Web
// Package: SOAP
// Module:  SOAPBody
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#include "Poco/Web/SOAPBody.h"
#include "Poco/Web/SOAPMessage.h"
#include "Poco/DOM/Document.h"
#include "Poco/DOM/Element.h"
#include "Poco/DOM/Text.h"
#include "Poco/DOM/NodeIterator.h"
#include "Poco/DOM/NodeFilter.h"
#include "Poco/DOM/NodeList.h"
#include "Poco/AutoPtr.h"


using Poco::AutoPtr;
using Poco::XML::Document;
using Poco::XML::NodeList;


namespace Poco {
namespace Web {


SOAPBody::SOAPBody(Document* pDoc): 
	SOAPElement(pDoc), 
	_pBody(0)
{
	AutoPtr<NodeList> pNode = pDoc->getElementsByTagName(envelopeTag());

	poco_check_ptr(pNode);
	int i = pNode->length();
	poco_assert(pNode->length() == 1);

	_pBody = pDoc->createElement(bodyTag());
	poco_check_ptr(_pBody);

	pNode->item(0)->appendChild(_pBody);
}


SOAPBody::~SOAPBody()
{
}


void SOAPBody::add(const std::string& tag, const std::string& content)
{
	SOAPElement::add(_pBody.get(), tag, content);
}


NodeList* SOAPBody::get(const std::string& name) const
{
	return _pBody->getElementsByTagName(name);
}


} } // namespace Poco::Web