// **********************************************************************
// This file was generated by a TARS parser!
// TARS version 3.0.13.
// **********************************************************************

#ifndef __MSGCONTENT_H_
#define __MSGCONTENT_H_

#include <map>
#include <string>
#include <vector>
#include "tup/Tars.h"
#include "tup/TarsJson.h"
using namespace std;


namespace otim
{
    enum MSG_CONTENT_TYPE
    {
        MCT_NONE = 0,
        MCT_TEXT = 1,
        MCT_IMAGE = 2,
        MCT_VOICE = 3,
        MCT_VEDIO = 4,
        MCT_FILE = 5,
        MCT_LOCATION = 6,
    };
    inline string etos(const MSG_CONTENT_TYPE & e)
    {
        switch(e)
        {
            case MCT_NONE: return "MCT_NONE";
            case MCT_TEXT: return "MCT_TEXT";
            case MCT_IMAGE: return "MCT_IMAGE";
            case MCT_VOICE: return "MCT_VOICE";
            case MCT_VEDIO: return "MCT_VEDIO";
            case MCT_FILE: return "MCT_FILE";
            case MCT_LOCATION: return "MCT_LOCATION";
            default: return "";
        }
    }
    inline int stoe(const string & s, MSG_CONTENT_TYPE & e)
    {
        if(s == "MCT_NONE")  { e=MCT_NONE; return 0;}
        if(s == "MCT_TEXT")  { e=MCT_TEXT; return 0;}
        if(s == "MCT_IMAGE")  { e=MCT_IMAGE; return 0;}
        if(s == "MCT_VOICE")  { e=MCT_VOICE; return 0;}
        if(s == "MCT_VEDIO")  { e=MCT_VEDIO; return 0;}
        if(s == "MCT_FILE")  { e=MCT_FILE; return 0;}
        if(s == "MCT_LOCATION")  { e=MCT_LOCATION; return 0;}

        return -1;
    }

    struct MsgText : public tars::TarsStructBase
    {
    public:
        static string className()
        {
            return "otim.MsgText";
        }
        static string MD5()
        {
            return "325d87d477a8cf7a6468ed6bb39da964";
        }
        MsgText()
        {
            resetDefautlt();
        }
        void resetDefautlt()
        {
            text = "";
            url = "";
        }
        template<typename WriterT>
        void writeTo(tars::TarsOutputStream<WriterT>& _os) const
        {
            _os.write(text, 0);
            if (url != "")
            {
                _os.write(url, 1);
            }
        }
        template<typename ReaderT>
        void readFrom(tars::TarsInputStream<ReaderT>& _is)
        {
            resetDefautlt();
            _is.read(text, 0, true);
            _is.read(url, 1, false);
        }
        tars::JsonValueObjPtr writeToJson() const
        {
            tars::JsonValueObjPtr p = new tars::JsonValueObj();
            p->value["text"] = tars::JsonOutput::writeJson(text);
            p->value["url"] = tars::JsonOutput::writeJson(url);
            return p;
        }
        string writeToJsonString() const
        {
            return tars::TC_Json::writeValue(writeToJson());
        }
        void readFromJson(const tars::JsonValuePtr & p, bool isRequire = true)
        {
            resetDefautlt();
            if(NULL == p.get() || p->getType() != tars::eJsonTypeObj)
            {
                char s[128];
                snprintf(s, sizeof(s), "read 'struct' type mismatch, get type: %d.", (p.get() ? p->getType() : 0));
                throw tars::TC_Json_Exception(s);
            }
            tars::JsonValueObjPtr pObj=tars::JsonValueObjPtr::dynamicCast(p);
            tars::JsonInput::readJson(text,pObj->value["text"], true);
            tars::JsonInput::readJson(url,pObj->value["url"], false);
        }
        void readFromJsonString(const string & str)
        {
            readFromJson(tars::TC_Json::getValue(str));
        }
        ostream& display(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.display(text,"text");
            _ds.display(url,"url");
            return _os;
        }
        ostream& displaySimple(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.displaySimple(text, true);
            _ds.displaySimple(url, false);
            return _os;
        }
    public:
        std::string text;
        std::string url;
    };
    inline bool operator==(const MsgText&l, const MsgText&r)
    {
        return l.text == r.text && l.url == r.url;
    }
    inline bool operator!=(const MsgText&l, const MsgText&r)
    {
        return !(l == r);
    }
    inline ostream& operator<<(ostream & os,const MsgText&r)
    {
        os << r.writeToJsonString();
        return os;
    }
    inline istream& operator>>(istream& is,MsgText&l)
    {
        std::istreambuf_iterator<char> eos;
        std::string s(std::istreambuf_iterator<char>(is), eos);
        l.readFromJsonString(s);
        return is;
    }

    struct MsgImage : public tars::TarsStructBase
    {
    public:
        static string className()
        {
            return "otim.MsgImage";
        }
        static string MD5()
        {
            return "9c2426dcf872b66b145cac9836e1fe56";
        }
        MsgImage()
        {
            resetDefautlt();
        }
        void resetDefautlt()
        {
            url = "";
            width = 0;
            height = 0;
            title = "";
        }
        template<typename WriterT>
        void writeTo(tars::TarsOutputStream<WriterT>& _os) const
        {
            _os.write(url, 0);
            if (width != 0)
            {
                _os.write(width, 1);
            }
            if (height != 0)
            {
                _os.write(height, 2);
            }
            if (title != "")
            {
                _os.write(title, 3);
            }
        }
        template<typename ReaderT>
        void readFrom(tars::TarsInputStream<ReaderT>& _is)
        {
            resetDefautlt();
            _is.read(url, 0, true);
            _is.read(width, 1, false);
            _is.read(height, 2, false);
            _is.read(title, 3, false);
        }
        tars::JsonValueObjPtr writeToJson() const
        {
            tars::JsonValueObjPtr p = new tars::JsonValueObj();
            p->value["url"] = tars::JsonOutput::writeJson(url);
            p->value["width"] = tars::JsonOutput::writeJson(width);
            p->value["height"] = tars::JsonOutput::writeJson(height);
            p->value["title"] = tars::JsonOutput::writeJson(title);
            return p;
        }
        string writeToJsonString() const
        {
            return tars::TC_Json::writeValue(writeToJson());
        }
        void readFromJson(const tars::JsonValuePtr & p, bool isRequire = true)
        {
            resetDefautlt();
            if(NULL == p.get() || p->getType() != tars::eJsonTypeObj)
            {
                char s[128];
                snprintf(s, sizeof(s), "read 'struct' type mismatch, get type: %d.", (p.get() ? p->getType() : 0));
                throw tars::TC_Json_Exception(s);
            }
            tars::JsonValueObjPtr pObj=tars::JsonValueObjPtr::dynamicCast(p);
            tars::JsonInput::readJson(url,pObj->value["url"], true);
            tars::JsonInput::readJson(width,pObj->value["width"], false);
            tars::JsonInput::readJson(height,pObj->value["height"], false);
            tars::JsonInput::readJson(title,pObj->value["title"], false);
        }
        void readFromJsonString(const string & str)
        {
            readFromJson(tars::TC_Json::getValue(str));
        }
        ostream& display(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.display(url,"url");
            _ds.display(width,"width");
            _ds.display(height,"height");
            _ds.display(title,"title");
            return _os;
        }
        ostream& displaySimple(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.displaySimple(url, true);
            _ds.displaySimple(width, true);
            _ds.displaySimple(height, true);
            _ds.displaySimple(title, false);
            return _os;
        }
    public:
        std::string url;
        tars::Int32 width;
        tars::Int32 height;
        std::string title;
    };
    inline bool operator==(const MsgImage&l, const MsgImage&r)
    {
        return l.url == r.url && l.width == r.width && l.height == r.height && l.title == r.title;
    }
    inline bool operator!=(const MsgImage&l, const MsgImage&r)
    {
        return !(l == r);
    }
    inline ostream& operator<<(ostream & os,const MsgImage&r)
    {
        os << r.writeToJsonString();
        return os;
    }
    inline istream& operator>>(istream& is,MsgImage&l)
    {
        std::istreambuf_iterator<char> eos;
        std::string s(std::istreambuf_iterator<char>(is), eos);
        l.readFromJsonString(s);
        return is;
    }

    struct MsgVoice : public tars::TarsStructBase
    {
    public:
        static string className()
        {
            return "otim.MsgVoice";
        }
        static string MD5()
        {
            return "75f1be2757c92eb6699b52ef20b9f989";
        }
        MsgVoice()
        {
            resetDefautlt();
        }
        void resetDefautlt()
        {
            url = "";
            time = 0;
        }
        template<typename WriterT>
        void writeTo(tars::TarsOutputStream<WriterT>& _os) const
        {
            _os.write(url, 0);
            if (time != 0)
            {
                _os.write(time, 1);
            }
        }
        template<typename ReaderT>
        void readFrom(tars::TarsInputStream<ReaderT>& _is)
        {
            resetDefautlt();
            _is.read(url, 0, true);
            _is.read(time, 1, false);
        }
        tars::JsonValueObjPtr writeToJson() const
        {
            tars::JsonValueObjPtr p = new tars::JsonValueObj();
            p->value["url"] = tars::JsonOutput::writeJson(url);
            p->value["time"] = tars::JsonOutput::writeJson(time);
            return p;
        }
        string writeToJsonString() const
        {
            return tars::TC_Json::writeValue(writeToJson());
        }
        void readFromJson(const tars::JsonValuePtr & p, bool isRequire = true)
        {
            resetDefautlt();
            if(NULL == p.get() || p->getType() != tars::eJsonTypeObj)
            {
                char s[128];
                snprintf(s, sizeof(s), "read 'struct' type mismatch, get type: %d.", (p.get() ? p->getType() : 0));
                throw tars::TC_Json_Exception(s);
            }
            tars::JsonValueObjPtr pObj=tars::JsonValueObjPtr::dynamicCast(p);
            tars::JsonInput::readJson(url,pObj->value["url"], true);
            tars::JsonInput::readJson(time,pObj->value["time"], false);
        }
        void readFromJsonString(const string & str)
        {
            readFromJson(tars::TC_Json::getValue(str));
        }
        ostream& display(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.display(url,"url");
            _ds.display(time,"time");
            return _os;
        }
        ostream& displaySimple(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.displaySimple(url, true);
            _ds.displaySimple(time, false);
            return _os;
        }
    public:
        std::string url;
        tars::Int32 time;
    };
    inline bool operator==(const MsgVoice&l, const MsgVoice&r)
    {
        return l.url == r.url && l.time == r.time;
    }
    inline bool operator!=(const MsgVoice&l, const MsgVoice&r)
    {
        return !(l == r);
    }
    inline ostream& operator<<(ostream & os,const MsgVoice&r)
    {
        os << r.writeToJsonString();
        return os;
    }
    inline istream& operator>>(istream& is,MsgVoice&l)
    {
        std::istreambuf_iterator<char> eos;
        std::string s(std::istreambuf_iterator<char>(is), eos);
        l.readFromJsonString(s);
        return is;
    }

    struct MsgVedio : public tars::TarsStructBase
    {
    public:
        static string className()
        {
            return "otim.MsgVedio";
        }
        static string MD5()
        {
            return "9c2426dcf872b66b145cac9836e1fe56";
        }
        MsgVedio()
        {
            resetDefautlt();
        }
        void resetDefautlt()
        {
            url = "";
            time = 0;
            size = 0;
            coverUrl = "";
        }
        template<typename WriterT>
        void writeTo(tars::TarsOutputStream<WriterT>& _os) const
        {
            _os.write(url, 0);
            _os.write(time, 1);
            _os.write(size, 2);
            if (coverUrl != "")
            {
                _os.write(coverUrl, 3);
            }
        }
        template<typename ReaderT>
        void readFrom(tars::TarsInputStream<ReaderT>& _is)
        {
            resetDefautlt();
            _is.read(url, 0, true);
            _is.read(time, 1, true);
            _is.read(size, 2, true);
            _is.read(coverUrl, 3, false);
        }
        tars::JsonValueObjPtr writeToJson() const
        {
            tars::JsonValueObjPtr p = new tars::JsonValueObj();
            p->value["url"] = tars::JsonOutput::writeJson(url);
            p->value["time"] = tars::JsonOutput::writeJson(time);
            p->value["size"] = tars::JsonOutput::writeJson(size);
            p->value["coverUrl"] = tars::JsonOutput::writeJson(coverUrl);
            return p;
        }
        string writeToJsonString() const
        {
            return tars::TC_Json::writeValue(writeToJson());
        }
        void readFromJson(const tars::JsonValuePtr & p, bool isRequire = true)
        {
            resetDefautlt();
            if(NULL == p.get() || p->getType() != tars::eJsonTypeObj)
            {
                char s[128];
                snprintf(s, sizeof(s), "read 'struct' type mismatch, get type: %d.", (p.get() ? p->getType() : 0));
                throw tars::TC_Json_Exception(s);
            }
            tars::JsonValueObjPtr pObj=tars::JsonValueObjPtr::dynamicCast(p);
            tars::JsonInput::readJson(url,pObj->value["url"], true);
            tars::JsonInput::readJson(time,pObj->value["time"], true);
            tars::JsonInput::readJson(size,pObj->value["size"], true);
            tars::JsonInput::readJson(coverUrl,pObj->value["coverUrl"], false);
        }
        void readFromJsonString(const string & str)
        {
            readFromJson(tars::TC_Json::getValue(str));
        }
        ostream& display(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.display(url,"url");
            _ds.display(time,"time");
            _ds.display(size,"size");
            _ds.display(coverUrl,"coverUrl");
            return _os;
        }
        ostream& displaySimple(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.displaySimple(url, true);
            _ds.displaySimple(time, true);
            _ds.displaySimple(size, true);
            _ds.displaySimple(coverUrl, false);
            return _os;
        }
    public:
        std::string url;
        tars::Int32 time;
        tars::Int32 size;
        std::string coverUrl;
    };
    inline bool operator==(const MsgVedio&l, const MsgVedio&r)
    {
        return l.url == r.url && l.time == r.time && l.size == r.size && l.coverUrl == r.coverUrl;
    }
    inline bool operator!=(const MsgVedio&l, const MsgVedio&r)
    {
        return !(l == r);
    }
    inline ostream& operator<<(ostream & os,const MsgVedio&r)
    {
        os << r.writeToJsonString();
        return os;
    }
    inline istream& operator>>(istream& is,MsgVedio&l)
    {
        std::istreambuf_iterator<char> eos;
        std::string s(std::istreambuf_iterator<char>(is), eos);
        l.readFromJsonString(s);
        return is;
    }

    struct MsgFile : public tars::TarsStructBase
    {
    public:
        static string className()
        {
            return "otim.MsgFile";
        }
        static string MD5()
        {
            return "074644cababcb11e8f54e9fdc06346f2";
        }
        MsgFile()
        {
            resetDefautlt();
        }
        void resetDefautlt()
        {
            url = "";
            name = "";
            size = 0;
        }
        template<typename WriterT>
        void writeTo(tars::TarsOutputStream<WriterT>& _os) const
        {
            _os.write(url, 0);
            _os.write(name, 1);
            _os.write(size, 2);
        }
        template<typename ReaderT>
        void readFrom(tars::TarsInputStream<ReaderT>& _is)
        {
            resetDefautlt();
            _is.read(url, 0, true);
            _is.read(name, 1, true);
            _is.read(size, 2, true);
        }
        tars::JsonValueObjPtr writeToJson() const
        {
            tars::JsonValueObjPtr p = new tars::JsonValueObj();
            p->value["url"] = tars::JsonOutput::writeJson(url);
            p->value["name"] = tars::JsonOutput::writeJson(name);
            p->value["size"] = tars::JsonOutput::writeJson(size);
            return p;
        }
        string writeToJsonString() const
        {
            return tars::TC_Json::writeValue(writeToJson());
        }
        void readFromJson(const tars::JsonValuePtr & p, bool isRequire = true)
        {
            resetDefautlt();
            if(NULL == p.get() || p->getType() != tars::eJsonTypeObj)
            {
                char s[128];
                snprintf(s, sizeof(s), "read 'struct' type mismatch, get type: %d.", (p.get() ? p->getType() : 0));
                throw tars::TC_Json_Exception(s);
            }
            tars::JsonValueObjPtr pObj=tars::JsonValueObjPtr::dynamicCast(p);
            tars::JsonInput::readJson(url,pObj->value["url"], true);
            tars::JsonInput::readJson(name,pObj->value["name"], true);
            tars::JsonInput::readJson(size,pObj->value["size"], true);
        }
        void readFromJsonString(const string & str)
        {
            readFromJson(tars::TC_Json::getValue(str));
        }
        ostream& display(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.display(url,"url");
            _ds.display(name,"name");
            _ds.display(size,"size");
            return _os;
        }
        ostream& displaySimple(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.displaySimple(url, true);
            _ds.displaySimple(name, true);
            _ds.displaySimple(size, false);
            return _os;
        }
    public:
        std::string url;
        std::string name;
        tars::Int32 size;
    };
    inline bool operator==(const MsgFile&l, const MsgFile&r)
    {
        return l.url == r.url && l.name == r.name && l.size == r.size;
    }
    inline bool operator!=(const MsgFile&l, const MsgFile&r)
    {
        return !(l == r);
    }
    inline ostream& operator<<(ostream & os,const MsgFile&r)
    {
        os << r.writeToJsonString();
        return os;
    }
    inline istream& operator>>(istream& is,MsgFile&l)
    {
        std::istreambuf_iterator<char> eos;
        std::string s(std::istreambuf_iterator<char>(is), eos);
        l.readFromJsonString(s);
        return is;
    }

    struct MsgLocation : public tars::TarsStructBase
    {
    public:
        static string className()
        {
            return "otim.MsgLocation";
        }
        static string MD5()
        {
            return "216c9658fc3d6cd4f3a7c64994f2ca59";
        }
        MsgLocation()
        {
            resetDefautlt();
        }
        void resetDefautlt()
        {
            lon = 0;
            lat = 0;
            title = "";
        }
        template<typename WriterT>
        void writeTo(tars::TarsOutputStream<WriterT>& _os) const
        {
            _os.write(lon, 0);
            _os.write(lat, 1);
            _os.write(title, 2);
        }
        template<typename ReaderT>
        void readFrom(tars::TarsInputStream<ReaderT>& _is)
        {
            resetDefautlt();
            _is.read(lon, 0, true);
            _is.read(lat, 1, true);
            _is.read(title, 2, true);
        }
        tars::JsonValueObjPtr writeToJson() const
        {
            tars::JsonValueObjPtr p = new tars::JsonValueObj();
            p->value["lon"] = tars::JsonOutput::writeJson(lon);
            p->value["lat"] = tars::JsonOutput::writeJson(lat);
            p->value["title"] = tars::JsonOutput::writeJson(title);
            return p;
        }
        string writeToJsonString() const
        {
            return tars::TC_Json::writeValue(writeToJson());
        }
        void readFromJson(const tars::JsonValuePtr & p, bool isRequire = true)
        {
            resetDefautlt();
            if(NULL == p.get() || p->getType() != tars::eJsonTypeObj)
            {
                char s[128];
                snprintf(s, sizeof(s), "read 'struct' type mismatch, get type: %d.", (p.get() ? p->getType() : 0));
                throw tars::TC_Json_Exception(s);
            }
            tars::JsonValueObjPtr pObj=tars::JsonValueObjPtr::dynamicCast(p);
            tars::JsonInput::readJson(lon,pObj->value["lon"], true);
            tars::JsonInput::readJson(lat,pObj->value["lat"], true);
            tars::JsonInput::readJson(title,pObj->value["title"], true);
        }
        void readFromJsonString(const string & str)
        {
            readFromJson(tars::TC_Json::getValue(str));
        }
        ostream& display(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.display(lon,"lon");
            _ds.display(lat,"lat");
            _ds.display(title,"title");
            return _os;
        }
        ostream& displaySimple(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.displaySimple(lon, true);
            _ds.displaySimple(lat, true);
            _ds.displaySimple(title, false);
            return _os;
        }
    public:
        tars::Double lon;
        tars::Double lat;
        std::string title;
    };
    inline bool operator==(const MsgLocation&l, const MsgLocation&r)
    {
        return tars::TC_Common::equal(l.lon,r.lon) && tars::TC_Common::equal(l.lat,r.lat) && l.title == r.title;
    }
    inline bool operator!=(const MsgLocation&l, const MsgLocation&r)
    {
        return !(l == r);
    }
    inline ostream& operator<<(ostream & os,const MsgLocation&r)
    {
        os << r.writeToJsonString();
        return os;
    }
    inline istream& operator>>(istream& is,MsgLocation&l)
    {
        std::istreambuf_iterator<char> eos;
        std::string s(std::istreambuf_iterator<char>(is), eos);
        l.readFromJsonString(s);
        return is;
    }


}



#endif