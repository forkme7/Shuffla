#ifndef QUERYPARAMETERS_H
#define QUERYPARAMETERS_H

#include "../../table/table_definition.hpp"
#include "../data_without_typing.hpp"
#include "functions/search_function.hpp"
#include "../../storage/row.hpp"
#include "../../kdtree/boundary.hpp"

class QueryParameters
{
public:
    enum Order {
        ASC,
        DESC
    };

    QueryParameters();
    virtual ~QueryParameters();

    bool set(const TableDefinition* table, const DataWithoutTyping& data);
    bool is_matching(const Row* row) const ;
    const std::vector<SearchFunction*> get_parameters() const;

    int offset;
    int limit;
    std::vector<std::pair<std::string, Order> > order_by;

protected:
private:
    std::vector<SearchFunction*> parameters;
    std::vector<SearchFunction*> registered_functions;

    void register_functions();
    bool is_special_property(const std::string& name) const;
    bool set_special_property(const TableDefinition* table_definition, const std::string& name, const std::string& value);
};

#endif // QUERYPARAMETERS_H
