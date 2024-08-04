#include <wx/wx.h>  //includes most used headers

class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame {
public:
    MyFrame(const wxString& title);

private:
    void OnQuit(wxCommandEvent& event);
    void OnSubmit(wxCommandEvent& event);

    wxTextCtrl *textCtrl;
    wxCheckBox *checkBox;

    wxDECLARE_EVENT_TABLE();

};

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_BUTTON(wxID_OK, MyFrame::OnSubmit)
wxEND_EVENT_TABLE()


wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    MyFrame* frame = new MyFrame("Lit Beat");
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title) {
 
    wxPanel *panel = new wxPanel(this);

    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);

    // Text input field
    wxStaticText *nameLabel = new wxStaticText(panel, wxID_ANY, "Name:");
    textCtrl = new wxTextCtrl(panel, wxID_ANY);

    // Checkbox
    checkBox = new wxCheckBox(panel, wxID_ANY, "Subscribe to newsletter");

    // Submit button
    wxButton *submitButton = new wxButton(panel, wxID_OK, "Submit");

    vbox->Add(nameLabel, 0, wxALL, 10);
    vbox->Add(textCtrl, 0, wxALL | wxEXPAND, 10);
    vbox->Add(checkBox, 0, wxALL, 10);
    vbox->Add(submitButton, 0, wxALL | wxALIGN_CENTER, 10);

    panel->SetSizer(vbox);

}

void MyFrame::OnSubmit(wxCommandEvent& event) {
    wxString name = textCtrl->GetValue();
    bool subscribed = checkBox->GetValue();

    wxString message;
    message.Printf("Name: %s\nSubscribed: %s", name, subscribed ? "Yes" : "No");

    wxMessageBox(message, "Form Data", wxOK | wxICON_INFORMATION);
}

void MyFrame::OnQuit(wxCommandEvent& event) {
    Close(true);
}
