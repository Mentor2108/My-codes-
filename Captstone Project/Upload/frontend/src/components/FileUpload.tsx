import {SdfFileUploader } from '@waypoint/react-components'

function FileUploadAndReview(props: { filesUploader: File[], setFilesUploader: React.Dispatch<React.SetStateAction<File[]>> }) {
    const {filesUploader, setFilesUploader } = props;

    return (
        <div style={{ fontFamily: "Arial, sans-serif" }} required-state="required">
            <h1><b>Upload your receipt</b></h1>
            <SdfFileUploader id="demo-component" file-size-max="10000000" onSdfChange={(evt) => {
                setFilesUploader(evt.detail)
            }} multiple={true} hideUploadButton={true} displayUploaded={true} value={filesUploader}></SdfFileUploader>
        </div>
    );
}

export default FileUploadAndReview;

