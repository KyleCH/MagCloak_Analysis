makePlot_check_all()
{

  gStyle->SetOptStat(0);

  vector< TString > v_infile;
  //  v_infile.push_back( TString("output/fitResults_run001_1layer_sheath.root") );
  //  v_infile.push_back( TString("output/fitResults_run002_1layer_sheath.root") );
  v_infile.push_back( TString("output/fitResults_run003_1layer_sheath.root") );
  v_infile.push_back( TString("output/fitResults_run004_2layer_sheath.root") );
  v_infile.push_back( TString("output/fitResults_run005_2layer_sheath.root") );
  v_infile.push_back( TString("output/fitResults_run006_3layer_sheath.root") );
  v_infile.push_back( TString("output/fitResults_run007_4layer_sheath.root") );
  v_infile.push_back( TString("output/fitResults_run008_2layer_cylinder.root") );
  v_infile.push_back( TString("output/fitResults_run009_2layer_cylinder.root") );
  //  v_infile.push_back( TString("output/fitResults_run010_1layer_sheath.root") );
  v_infile.push_back( TString("output/fitResults_run011_1layer_sheath.root") );
  v_infile.push_back( TString("output/fitResults_run012_1layer_sheath.root") );
  v_infile.push_back( TString("output/fitResults_run013_1layer_sheath.root") );
  v_infile.push_back( TString("output/fitResults_run014_1layer_sheath.root") );
  v_infile.push_back( TString("output/fitResults_run015_1layer_sheath.root") );
  v_infile.push_back( TString("output/fitResults_run016_1layer_sheath.root") );
  v_infile.push_back( TString("output/fitResults_run017_2layer_sheath.root") );
  v_infile.push_back( TString("output/fitResults_run018_1layer_sheath.root") );
  v_infile.push_back( TString("output/fitResults_run019_1layer_sheath.root") );
  v_infile.push_back( TString("output/fitResults_run020_1layer_sheath.root") );
  v_infile.push_back( TString("output/fitResults_run021_1layer.root") );
  for ( unsigned f = 0; f < v_infile.size(); f++ )
    {
      cout << "Plot " << v_infile.at(f) << endl;

      TCanvas *c0 = new TCanvas();

      TFile *fin = new TFile( v_infile.at(f) );
      TTree *tin = (TTree*)fin->Get("fitResults");
      tin->Draw("bshield:bext:bshield_err:bext_err");

      TGraphErrors *gshield = new TGraphErrors( tin->GetEntries(), tin->GetV2(), tin->GetV1(), tin->GetV4(), tin->GetV3() );
      gshield->SetTitle(v_infile.at(f));
      gshield->GetXaxis()->SetTitle("B_{ext} [mT]");
      gshield->GetYaxis()->SetTitle("B_{shield} [mT]");

      gshield->Draw("AP");

      fin->Close();

      if ( f == 0 )
        c0->Print("plot_check_all.ps(");
      else if ( f == v_infile.size() - 1 )
        c0->Print("plot_check_all.ps)");
      else
        c0->Print("plot_check_all.ps");

    }



}
