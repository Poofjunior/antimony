#include <Python.h>

#include "node/meta.h"
#include "node/node.h"

#include "node/manager.h"

#include "datum/name_datum.h"
#include "datum/float_datum.h"
#include "datum/shape_datum.h"
#include "datum/function_datum.h"
#include "datum/string_datum.h"
#include "datum/script_datum.h"

////////////////////////////////////////////////////////////////////////////////

Node* ScriptNode(QString name, QString x, QString y, QString z,
                 QString script, QObject* parent)
{
    Node* n = new Node(NodeType::SCRIPT, parent);
    new NameDatum("name", name, n);
    new FloatDatum("_x", x, n);
    new FloatDatum("_y", y, n);
    new FloatDatum("_z", z, n);
    new ScriptDatum("script", script, n);
    return n;
}

Node* ScriptNode(float x, float y, float z, float scale,
                 QObject* parent)
{
    Q_UNUSED(scale);

    Node* n = new Node(NodeType::SCRIPT, parent);
    new NameDatum("name", NodeManager::manager()->getName("a"), n);
    new FloatDatum("_x", QString::number(x), n);
    new FloatDatum("_y", QString::number(y), n);
    new FloatDatum("_z", QString::number(z), n);
    new ScriptDatum("script",
             "from fab import shapes\n\n"
             "output('c', shapes.circle(0, 0, 1))", n);
    return n;
}