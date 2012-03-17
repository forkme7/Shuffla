#ifndef TYPESTRING_H
#define TYPESTRING_H

#include <string>

#include "type.hpp"

class TypeString : public Type
{
public:
    typedef std::string TYPE;

    virtual std::string get_name() const {
        return "string";
    }

    TypeString(const TYPE value);
    virtual ~TypeString();

    virtual bool is_correct_value(const std::string& value) const ;
    virtual bool is_correct_function(const std::string& function_name) const ;

    virtual std::string to_string() const;
    TYPE get_value() const ;
protected:
private:
    TYPE value;
};

#endif // TYPESTRING_H
