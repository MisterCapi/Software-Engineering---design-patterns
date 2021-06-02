#include <iostream>
#include <vector>

using namespace std;


class Data {
public:
    string text;
};


class Document : public Data {
public:
    string text;
    explicit Document(string text){
        this->text = text;
    }
};


class ArchivedDocument : public Data {
public:
    string text;
    ArchivedDocument(Document document){
        this->text = document.text;
    }
};


class Archive {
public:
    Document getLastVersion(){
        ArchivedDocument lestDoc = archivedDocs.back();
        archivedDocs.pop_back();
        return Document(lestDoc.text);
    }

    void archiveDocument(ArchivedDocument doc){
        archivedDocs.push_back(doc);
    }

private:
    vector<ArchivedDocument> archivedDocs;
};


int main() {
    cout << "Create docs...\n";

    Document doc1 = Document("DOC1");
    Document doc2 = Document("DOC2");
    Document doc3 = Document("DOC3");

    cout << "Archive them...\n";

    ArchivedDocument arch1 = ArchivedDocument(doc1);
    ArchivedDocument arch2 = ArchivedDocument(doc2);
    ArchivedDocument arch3 = ArchivedDocument(doc3);

    Archive archive = Archive();

    archive.archiveDocument(arch1);
    archive.archiveDocument(arch2);
    archive.archiveDocument(arch3);

    cout << "Restore last archived (should be doc3 .. to 1)\n";

    Document lastArchivedDoc = archive.getLastVersion();
    cout << lastArchivedDoc.text << "\n";

    Document lastArchivedDoc2 = archive.getLastVersion();
    cout << lastArchivedDoc2.text << "\n";

    Document lastArchivedDoc3 = archive.getLastVersion();
    cout << lastArchivedDoc3.text << "\n";



    return 0;
}
