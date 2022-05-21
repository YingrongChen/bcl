// (c) Copyright BCL @ Vanderbilt University 2014
// (c) BCL Homepage: http://www.meilerlab.org/bclcommons
// (c) BCL Code Repository: https://github.com/BCLCommons/bcl
// (c)
// (c) The BioChemical Library (BCL) was originally developed by contributing members of the Meiler Lab @ Vanderbilt University.
// (c)
// (c) The BCL is now made available as an open-source software package distributed under the permissive MIT license,
// (c) developed and maintained by the Meiler Lab at Vanderbilt University and contributing members of the BCL Commons.
// (c)
// (c) External code contributions to the BCL are welcome. Please visit the BCL Commons GitHub page for information on how you can contribute.
// (c)
// (c) This file is part of the BCL software suite and is made available under the MIT license.
// (c)

// include example header
#include "example.h"
// include the header of the class which this example is for
#include "release/bcl_app_alignment.h"

// includes from bcl - sorted alphabetically
#include "example_application_example_helper.h"
#include "align/bcl_align.h"
#include "io/bcl_io_file.h"

// external includes - sorted alphabetically

namespace bcl
{
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //!
  //! @example example_app_alignment.cpp
  //!
  //! @author heinzes1
  //! @date Jan 14, 2012
  //! @remarks status complete
  //!
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  class ExampleAppAlignment :
    public ExampleInterface
  {
  public:

    ExampleAppAlignment *Clone() const
    {
      return new ExampleAppAlignment( *this);
    }

  /////////////////
  // data access //
  /////////////////

    //! @brief returns class name
    //! @return the class name as const ref std::string
    const std::string &GetClassIdentifier() const
    {
      return GetStaticClassName( *this);
    }

    int Run() const
    {
    ////////////////
    // unit tests //
    ////////////////

      // unit tests of application class functions, if applicable, go here

      {
      ////////////////////
      // initialization //
      ////////////////////

        // create a helper to run this application
        ApplicationExampleHelper alignment_app( app::Alignment::Alignment_Instance);

      ///////////
      // files //
      ///////////

        // create filenames for any input/output files used/generated by the test

      ///////////////////////
      // integration tests //
      ///////////////////////

        const std::string output_prefix( AddExampleOutputPathToFilename( align::GetNamespaceIdentifier(), "1IE9A"));
        const std::string output_format( "pir");

        // set flags; check valid and invalid command lines; check results
        alignment_app.SetFlag( "fastas", AddExampleInputPathToFilename( e_Biology, "1IE9A.fasta"));
        alignment_app.AddParameterToFlag( "fastas", AddExampleInputPathToFilename( e_Biology, "1IE9A.fasta"));
        alignment_app.SetFlag( "blosum62", "1.0");
        alignment_app.SetFlag( "pam250", "1.0");
        alignment_app.SetFlag( "blast", "1.0");
        alignment_app.SetFlag( "psipred", "1.0");
        alignment_app.SetFlag( "polarizability", "1.0");
        alignment_app.SetFlag( "volume", "1.0");
        alignment_app.SetFlag( "hydrophobicity", "1.0");
        alignment_app.SetFlag( "isoelectric", "1.0");
        alignment_app.SetFlag( "tfe_white", "1.0");
        alignment_app.SetFlag( "open_gap", "-1.0");
        alignment_app.SetFlag( "extend_gap", "-0.5");
        alignment_app.SetFlag( "open_boundary_gap", "0.0");
        alignment_app.SetFlag( "extend_boundary_gap", "0.0");
        alignment_app.SetFlag( "outputformat", output_format);
        alignment_app.SetFlag( "outputprefix", output_prefix);

        // check a valid set of flags.  Since all later commands depend on this command succeeding, make it an assert
        BCL_ExampleCheck( alignment_app.CheckCommandString( true), true);

        // run a valid set of flags, check that the return status is 0
        if( BCL_ExampleCheck( alignment_app.RunCommand(), 0))
        {
          // file containing the correct alignment
          const std::string calculated_alignment_file( output_prefix + "." + output_format);
          const std::string correct_alignment_file( calculated_alignment_file + ".correct");

          // if the application ran successfully, check that files match
          BCL_ExampleIndirectCheck
          (
            io::File::FilesMatch( correct_alignment_file, calculated_alignment_file),
            true,
            "Compare generated alignment and correct alignment"
          );
        }
      }

      {
      ////////////////////
      // initialization //
      ////////////////////

        // create a helper to run this application
        ApplicationExampleHelper alignment_app( app::Alignment::Alignment_Instance);

      ///////////
      // files //
      ///////////

        // create filenames for any input/output files used/generated by the test
        const std::string output_prefix( AddExampleOutputPathToFilename( align::GetNamespaceIdentifier(), "align_1fms_1fm5"));
        const std::string output_format( "standard");

      ///////////////////////
      // integration tests //
      ///////////////////////

        // set flags; check valid and invalid command lines; check results
        alignment_app.SetFlag( "fastas", AddExampleInputPathToFilename( e_Biology, "1fms_.fasta"));
        alignment_app.AddParameterToFlag( "fastas", AddExampleInputPathToFilename( e_Biology, "1f5mA.fasta"));
        alignment_app.SetFlag( "blosum62", "1.0");
        alignment_app.SetFlag( "pam250", "1.0");
        alignment_app.SetFlag( "blast", "1.0");
        alignment_app.SetFlag( "psipred", "1.0");
        alignment_app.SetFlag( "jufo", "1.0");
        alignment_app.SetFlag( "polarizability", "1.0");
        alignment_app.SetFlag( "volume", "1.0");
        alignment_app.SetFlag( "hydrophobicity", "1.0");
        alignment_app.SetFlag( "isoelectric", "1.0");
        alignment_app.SetFlag( "tfe_white", "1.0");
        alignment_app.SetFlag( "open_gap", "-1.0");
        alignment_app.SetFlag( "extend_gap", "-0.5");
        alignment_app.SetFlag( "open_boundary_gap", "0.0");
        alignment_app.SetFlag( "extend_boundary_gap", "0.0");
        alignment_app.SetFlag( "outputformat", output_format);
        alignment_app.SetFlag( "outputprefix", output_prefix);

        // check a valid set of flags.  Since all later commands depend on this command succeeding, make it an assert
        BCL_ExampleCheck( alignment_app.CheckCommandString( true), true);

        // run a valid set of flags, check that the return status is 0
        if( BCL_ExampleCheck( alignment_app.RunCommand(), 0))
        {
          // file containing the correct alignment
          const std::string calculated_alignment_file( output_prefix + "." + output_format);
          const std::string correct_alignment_file( calculated_alignment_file + ".correct");

          // if the application ran successfully, check that files match
          BCL_ExampleIndirectCheck
          (
            io::File::FilesMatch( correct_alignment_file, calculated_alignment_file),
            true,
            "Compare generated alignment and correct alignment"
          );
        }
      }

      {
      ////////////////////
      // initialization //
      ////////////////////

        // create a helper to run this application
        ApplicationExampleHelper alignment_app( app::Alignment::Alignment_Instance);

      ///////////
      // files //
      ///////////

        // create filenames for any input/output files used/generated by the test
        const std::string output_prefix( AddExampleOutputPathToFilename( align::GetNamespaceIdentifier(), "score_1fms_1fm5"));
        const std::string output_format( "standard");
        const std::string input_filename( AddExampleOutputPathToFilename( align::GetNamespaceIdentifier(), "align_1fms_1fm5.standard"));

      ///////////////////////
      // integration tests //
      ///////////////////////

        // set flags; check valid and invalid command lines; check results
        alignment_app.SetFlag( "score_alignment", input_filename);
        alignment_app.SetFlag( "blosum62", "1.0");
        alignment_app.SetFlag( "pam250", "1.0");
        alignment_app.SetFlag( "polarizability", "1.0");
        alignment_app.SetFlag( "volume", "1.0");
        alignment_app.SetFlag( "hydrophobicity", "1.0");
        alignment_app.SetFlag( "isoelectric", "1.0");
        alignment_app.SetFlag( "tfe_white", "1.0");
        alignment_app.SetFlag( "open_gap", "-1.0");
        alignment_app.SetFlag( "extend_gap", "-0.5");
        alignment_app.SetFlag( "open_boundary_gap", "0.0");
        alignment_app.SetFlag( "extend_boundary_gap", "0.0");
        alignment_app.SetFlag( "outputformat", output_format);
        alignment_app.SetFlag( "outputprefix", output_prefix);

        // check a valid set of flags.  Since all later commands depend on this command succeeding, make it an assert
        BCL_ExampleCheck( alignment_app.CheckCommandString( true), true);

        // run a valid set of flags, check that the return status is 0
        if( BCL_ExampleCheck( alignment_app.RunCommand(), 0))
        {
          // file containing the correct alignment
          const std::string calculated_alignment_file( output_prefix + "." + output_format);
          const std::string correct_alignment_file( calculated_alignment_file + ".correct");

          // if the application ran successfully, check that files match
          BCL_ExampleIndirectCheck
          (
            io::File::FilesMatch( correct_alignment_file, calculated_alignment_file),
            true,
            "Compare generated alignment and correct alignment"
          );
        }
      }

      return 0;
    }

    static const ExampleClass::EnumType s_Instance;

  }; //end ExampleAppAlignment

  const ExampleClass::EnumType ExampleAppAlignment::s_Instance( GetExamples().AddEnum( ExampleAppAlignment()));

} // namespace bcl